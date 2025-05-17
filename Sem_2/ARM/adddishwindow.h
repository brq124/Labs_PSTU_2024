#ifndef ADDDISHWINDOW_H
#define ADDDISHWINDOW_H

#include <QDialog>
#include <Dish.h>

namespace Ui {
class addDishWindow;
}

class addDishWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addDishWindow(QWidget *parent = nullptr);
    ~addDishWindow();


private slots:
    void onAddDishClicked();

signals:
    void dishAdded(const Dish& dish);

private:
    Ui::addDishWindow *ui;
};

#endif // ADDDISHWINDOW_H
