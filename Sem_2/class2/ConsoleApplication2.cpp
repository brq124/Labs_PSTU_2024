#include <iostream>
#include "Receipt.h"
using namespace std;

Receipt makeReceipt()
{
    unsigned int number;
    std::string date;
    double amount;
    cout << "Введите номер" << endl;
    cin >> number;
    cout << "Введите дату" << endl;
    cin >> date;
    cout << "Введите стоимость" << endl;
    cin >> amount;
    Receipt receipt(number, date, amount);
    return receipt;
}

void printReceipt(Receipt receipt)
{
    receipt.show();
}

int main()
{
    setlocale(LC_ALL, "ru");
    //конструктор без параметров
    Receipt receipt1;
    receipt1.show();
    //конструктор с параметрами
    Receipt receipt2(8, "5.12.2006", 35);
    receipt2.show();
    //конструктор копирования
    Receipt receipt3 = receipt2;
    receipt3.setNumber(6);
    receipt3.setDate("10.10.2002");
    receipt3.setAmount(29);
    //конструктор копирования
    printReceipt(receipt3);
    //конструктор копирования
    receipt1 = makeReceipt();
    receipt1.show();
}

