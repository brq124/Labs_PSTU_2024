#include "adddishwindow.h"
#include "ui_adddishwindow.h"
#include "Dish.h"
#include <QMessageBox>
addDishWindow::addDishWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addDishWindow)
{
    ui->setupUi(this);

    connect(ui->dishAddButton, &QPushButton::clicked, this, &addDishWindow::onAddDishClicked);
    connect(ui->dishCancelButton, &QPushButton::clicked, this, &addDishWindow::close);
}

addDishWindow::~addDishWindow()
{
    delete ui;
}


void addDishWindow::onAddDishClicked()
{
    Dish dish{
        ui->dishNameLineEdit->text(),
        ui->caloriesSpinBox->value(),
        ui->proteinsSpinBox->value(),
        ui->fatsSpinBox->value(),
        ui->carbohydratesSpinBox->value()
    };
    if(!dish.isValid())
    {
        QMessageBox::warning(this, "Ошибка", "Неверно введеные значения!\nБлюдо должно иметь название и калорийность.");
        return;
    }
    emit dishAdded(dish);
    this->close();
}

