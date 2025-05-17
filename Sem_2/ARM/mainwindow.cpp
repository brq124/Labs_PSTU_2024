#include "mainwindow.h"
#include <QTableView>
#include "ui_mainwindow.h"
#include <QSettings>
#include "caloriescalculator.h"
#include <QStandardItemModel>
#include <QIcon>
#include "adddishwindow.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDir>
#include <QDateTime>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 620);
    this->setWindowTitle("АРМ диетолога");

    // верхняя менюшка
    connect(ui->homeButton, &QPushButton::clicked, this, &MainWindow::onHomeButtonClicked);
    connect(ui->diaryButton, &QPushButton::clicked, this, &MainWindow::onDiaryButtonClicked);
    connect(ui->profileButton, &QPushButton::clicked, this, &MainWindow::onProfileButtonClicked);

    // дневник
    connect(ui->addDishButton, &QPushButton::clicked, this, &MainWindow::onAddDishButtonClicked);
    connect(ui->deleteDishButton, &QPushButton::clicked, this, &MainWindow::onDeleteDishButtonClicked);

    // профиль
    connect(ui->saveProfilePushButton, &QPushButton::clicked, this, &MainWindow::onSaveProfileButtonClicked);
    connect(ui->infoButton, &QPushButton::clicked, this, &MainWindow::onInfoButtonClicked);

    //ui->stackedWidget->addWidget(page1);

    setupDb();
    loadProfile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onHomeButtonClicked() {
    ui->stackedWidget->setCurrentIndex(0);
}
void MainWindow::onDiaryButtonClicked() {
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::onProfileButtonClicked() {
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::setupDb()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("myDatabase.db");
    if(!db.open())
    {
        qDebug() << "Ошибка подключения к БД:" << 2;
    }
    else
    {
        qDebug() << "Успешное подключение к БД!";
    }
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS dishes ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "date TEXT,"
               "name TEXT,"
               "calories INTEGER,"
               "proteins INTEGER,"
               "fats INTEGER,"
               "carbohydrates INTEGER,"
               "time TEXT"
               ")"
               );

    model = new QSqlTableModel(this);
    model->setTable("dishes");
    model->select();

    ui->tableWidget->setModel(model);
    ui->tableWidget->hideColumn(model->fieldIndex("id"));
    ui->tableWidget->hideColumn(model->fieldIndex("date"));
    ui->tableWidget->setEditTriggers(QTableView::NoEditTriggers);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    model->setHeaderData(model->fieldIndex("name"), Qt::Horizontal, "Название");
    model->setHeaderData(model->fieldIndex("calories"), Qt::Horizontal, "Калории");
    model->setHeaderData(model->fieldIndex("proteins"), Qt::Horizontal, "Белки");
    model->setHeaderData(model->fieldIndex("fats"), Qt::Horizontal, "Жиры");
    model->setHeaderData(model->fieldIndex("carbohydrates"), Qt::Horizontal, "Углеводы");
    model->setHeaderData(model->fieldIndex("time"), Qt::Horizontal, "Время");
}

void MainWindow::onAddDishButtonClicked()
{
    addDishWindow dw;
    connect(&dw, &addDishWindow::dishAdded, this, &MainWindow::onDishAdded);
    dw.setFixedSize(400, 260);
    dw.setWindowTitle("Добавить блюдо");
    dw.exec();
}
void MainWindow::onDeleteDishButtonClicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM dishes WHERE id=:id");
    int row = ui->tableWidget->currentIndex().row();
    int column = model->fieldIndex("id");
    QModelIndex index = model->index(row, column);
    QString id = model->data(index).toString();
    query.bindValue(":id", id);
    query.exec();
    model->select();
    UpdatePages();
}
void MainWindow::onDishAdded(const Dish &dish)
{
    QSqlQuery query;
    query.prepare("INSERT into dishes (date, name, calories, proteins, fats, carbohydrates, time)"
                  "VALUES (:date, :name, :calories, :proteins, :fats, :carbohydrates, :time)");
    query.bindValue(":date", QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    query.bindValue(":name", dish.name);
    query.bindValue(":calories", dish.calories);
    query.bindValue(":proteins", dish.proteins);
    query.bindValue(":fats", dish.fats);
    query.bindValue(":carbohydrates", dish.carbohydrates);
    query.bindValue(":time", QDateTime::currentDateTime().toString("hh:mm:ss"));
    query.exec();
    model->select();
    UpdatePages();
}

Dish MainWindow::sumTableDish()
{
    QSqlQuery query;
    query.prepare("SELECT SUM(calories), SUM(proteins), SUM(fats), SUM(carbohydrates) FROM dishes WHERE date=:date");
    query.bindValue(":date", QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    if(query.exec())
    {
        if(query.next())
        {
            int totalCalories = query.value(0).toInt();
            int totalProteins = query.value(1).toInt();
            int totalFats = query.value(2).toInt();
            int totalCarbs = query.value(3).toInt();
            Dish dish{
                "sum",
                totalCalories,
                totalProteins,
                totalFats,
                totalCarbs
            };
            return dish;
        }
    }
}

void MainWindow::setSelectedGender(const UserPreference::Gender& gender)
{
    if(gender == UserPreference::MALE)
        ui->genderMaleRadioButton->setChecked(true);
    else
        ui->genderFemaleRadioButton->setChecked(true);;
}
UserPreference::Gender MainWindow::getSelectedGender()
{
    if(ui->genderButtonGroup->checkedButton() == ui->genderMaleRadioButton)
        return UserPreference::MALE;
    else
        return UserPreference::FEMALE;
}
void MainWindow::setSelectedGoal(const UserPreference::Goal& goal)
{
    if(goal == UserPreference::LOSS)
        ui->lossButton->setChecked(true);
    else
        ui->gainButton->setChecked(true);
}
UserPreference::Goal MainWindow::getSelectedGoal()
{
    if(ui->goalButtonGroup->checkedButton() == ui->lossButton)
        return UserPreference::LOSS;
    else
        return UserPreference::GAIN;
}

void MainWindow::onInfoButtonClicked()
{
    QMessageBox::information(this, "Информация", "Базовый метаболизм расчитывается по формуле Формула Миффлина-Сан Жеора.\n\n"
                                                 "Сидячий = 1,2 — минимальная активность, сидячая работа без значительных физических нагрузок;\n\n"
                                                 "Легкий = 1,375 — низкий уровень уровень активности: много ходите, катаетесь на велосипеде, время от времени играете в дворовый волейбол;\n\n"
                                                 "Умеренный = 1,55 — умеренный уровень активности: вы интенсивно тренируетесь 30-60 минут три-четыре раза в неделю;\n\n"
                                                 "Интенсивный = 1,7 — интенсивный уровень активности. Активное занятие спортом 5-7 дней в неделю;\n\n"
                                                 "Экстремальный = 1,9 — экстремальный уровень: занятия спортом с несколькими тренировками каждый день, физически затратные работы.");
}


void MainWindow::loadProfile()
{
    QSettings settings("MyCompany", "MyApp");
    pref = UserPreference{
        static_cast<UserPreference::Gender>(settings.value("UserPreference/gender").toInt()),
        settings.value("UserPreference/age", 19).toInt(),
        settings.value("UserPreference/weight", 67).toInt(),
        settings.value("UserPreference/height", 177).toInt(),
        settings.value("UserPreference/training", 1).toInt(),
        static_cast<UserPreference::TrainingActivity>(settings.value("UserPreference/trainingActivity", 4).toInt()),
        static_cast<UserPreference::Goal>(settings.value("UserPreference/goal", 1).toInt())
    };
    setSelectedGender(pref.gender);
    ui->ageSpinBox->setValue(pref.age);
    ui->weightSpinBox->setValue(pref.weight);
    ui->heightSpinBox->setValue(pref.height);
    ui->trainingSpinBox->setValue(pref.training);
    ui->trainingactivityComboBox->setCurrentIndex(pref.trainingActivity);
    setSelectedGoal(pref.goal);

    UpdatePages();
}

void MainWindow::saveProfile()
{
    QSettings settings("MyCompany", "MyApp");
    pref = UserPreference{
        getSelectedGender(),
        ui->ageSpinBox->value(),
        ui->weightSpinBox->value(),
        ui->heightSpinBox->value(),
        ui->trainingSpinBox->value(),
        static_cast<UserPreference::TrainingActivity>(ui->trainingactivityComboBox->currentIndex()),
        getSelectedGoal()
    };
    settings.setValue("UserPreference/gender", pref.gender);
    settings.setValue("UserPreference/age", pref.age);
    settings.setValue("UserPreference/weight", pref.weight);
    settings.setValue("UserPreference/height", pref.height);
    settings.setValue("UserPreference/training", pref.training);
    settings.setValue("UserPreference/trainingActivity", pref.trainingActivity);
    settings.setValue("UserPreference/goal", pref.goal);

    UpdatePages();
}

void MainWindow::onSaveProfileButtonClicked()
{
    saveProfile();
}

void MainWindow::UpdatePages()
{
    CaloriesCalculator calc;
    Dish dish = sumTableDish();
    int BRM = calc.calculateBRM(pref);
    int TDEE = calc.calculateTDEE(pref);
    int surplus = calc.calculateSurplus(pref);
    int targetCalories = calc.calculateTargetCalories(pref);
    int consumedCalories = dish.calories;
    int remainingCalories = targetCalories - consumedCalories;
    if(remainingCalories < 0) remainingCalories = 0;

    // home
    ui->targetCaloriesHomeLabel->setText(QString("%1 ккал.").arg(targetCalories));
    ui->remainingCaloriesHomeLabel->setText(QString("%1 ккал.").arg(remainingCalories));
    ui->consumedCaloriesHomeLabel->setText(QString("%1 ккал.").arg(dish.calories));

    ui->proteinsHomeLabel->setText(QString("%1 гр.").arg(dish.proteins));
    ui->fatsHomeLabel->setText(QString("%1 гр.").arg(dish.fats));
    ui->carbohydratesHomeLabel->setText(QString("%1 гр.").arg(dish.carbohydrates));
    if(pref.goal == UserPreference::LOSS)
        ui->goalHomeLabel->setText(QString("Похудение"));
    else
        ui->goalHomeLabel->setText(QString("Набор массы"));

    // дневник
    ui->sumDishLabel->setText(QString("%1 ккал.").arg(dish.calories));

    // профиль
    ui->BMRProfileLabel->setText(QString("%1 ккал.").arg(BRM));
    ui->TDEEProfileLabel->setText(QString("%1 ккал.").arg(TDEE));
    ui->surplusProfileLabel->setText(QString("%1 ккал.").arg(qAbs(surplus)));
    ui->targetCaloriesProfileLabel->setText(QString("%1 ккал.").arg(targetCalories));
    if(pref.goal == UserPreference::LOSS)
        ui->surplusProfileTextLabel->setText(QString("Дефицит:"));
    else
        ui->surplusProfileTextLabel->setText(QString("Профицит:"));
}










