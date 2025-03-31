#include <iostream>
#include "Phone.h"
using namespace std;

Phone makePhone(unsigned int first, float second)
{
    Phone phone;
    phone.Init(first, second);
    return phone;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Phone p1;
    p1.Init(2, 10);
    p1.Show();
    cout << "Общая стоимость: " << p1.Cost() << endl;

    Phone* p2 = new Phone();
    p2->Read();
    p2->Show();
    cout << "Общая стоимость: " << p2->Cost() << endl;

    Phone phones[3];
    for (int i = 0; i < 3; i++)
    {
        phones[i].Read();
    }
    for (int i = 0; i < 3; i++)
    {
        phones[i].Show();
        cout << "Общая стоимость: " << phones[i].Cost() << endl;
    }

    unsigned int a;
    float b;
    cin >> a;
    cin >> b;
    Phone p3 = makePhone(a, b);
    p3.Show();
    cout << "Общая стоимость: " << p3.Cost() << endl;
    return 0;
}

