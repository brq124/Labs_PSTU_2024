#include <iostream>
#define f(x, y, R) (pow(x, 2) + pow(y, 2) <= pow(R, 2))
using namespace std;

int belong(int R, int n, ...);

int main()
{
    setlocale(LC_ALL, "ru");
    const int R = 10;
    cout << "Первый вызов функции: " << belong(R, 1, 6, 4) << endl;
    cout << "Второй вызов функции: " << belong(R, 4, 7, 2, 8, 5, 9, 4, 6, 2) << endl;
    cout << "Третий вызов функции: " << belong(R, 0, 7, 2, 8, 5, 9, 4, 6, 2) << endl;
    return 0;
}

int belong(int R, int n, ...)
{
    int* p = &n;
    int x, y;
    cout << *p;
    /*
    while (n != 0)
    {
        x = *(p++);
        y = *(p++);
        cout << x << ' ' << y << endl;
        p++;
        n--;
    }*/
    return 1;
};
