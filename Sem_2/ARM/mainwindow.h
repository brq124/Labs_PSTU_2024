#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Dish.h"
#include "qsqltablemodel.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <caloriescalculator.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onHomeButtonClicked();
    void onDiaryButtonClicked();
    void onProfileButtonClicked();

    void onSaveProfileButtonClicked();

    void onAddDishButtonClicked();
    void onDeleteDishButtonClicked();

    void onInfoButtonClicked();

    void onDishAdded(const Dish &dish);

private:
    Ui::MainWindow *ui;
    UserPreference pref;
    QSqlDatabase db;
    QSqlTableModel* model;

    void loadProfile();
    void saveProfile();
    void setSelectedGender(const UserPreference::Gender& gender);
    UserPreference::Gender getSelectedGender();
    void setSelectedGoal(const UserPreference::Goal& goal);
    UserPreference::Goal getSelectedGoal();
    Dish sumTableDish();
    void UpdatePages();
    void setupDb();
};
#endif // MAINWINDOW_H
