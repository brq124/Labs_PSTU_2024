#include <iostream>
#include "Pair.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    Pair p1, p2;
    cout << "Введите первую пару чисел" << endl;
    cin >> p1;
    cout << "Введите вторую пару чисел" << endl;
    cin >> p2;
    cout << "Пара #1: " << p1 << endl;
    ++p1;
    cout << "После операции посткремента: " << p1 << endl;
    cout << "Пара #2: " << p2 << endl;
    p2++;
    cout << "После операции инкремента: " << p2 << endl;
    if (p1 > p2)
    {
        cout << "Пара " << p1 << " больше, чем пара " << p2 << endl;
    }
    else
    {
        cout << "Пара " << p1 << " не больше, чем пара " << p2 << endl;
    }
    p1 = p2;
    cout << "Теперь пара #1 равна паре #2!" << endl;
    cout << "Пара #1: " << p1 << endl;
    cout << "Пара #2: " << p2 << endl;
}

