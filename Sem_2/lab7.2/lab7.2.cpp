#include <iostream>
#include <cstdarg>
#define f(x, y, R) ((pow(x, 2) + pow(y, 2)) <= pow(R, 2))
using namespace std;

int belong(int R, int n, ...);

int main()
{
    setlocale(LC_ALL, "ru");
    const int R = 10;
    cout << "Первый вызов функции: " << belong(R, 1, 4, 6) << endl;
    cout << "Второй вызов функции: " << belong(R, 4, 7, 2, 8, 12, 1, 4, 8, 8) << endl;
    cout << "Третий вызов функции: " << belong(R, 9, 15, 2, 3, 16, 9, 4, 6, 2, 5, 2, 13, 7, 5, 3, 8, 6, 12, 9) << endl;
    return 0;
}

int belong(int R, int n, ...)
{
    va_list p;
    va_start(p, n);
    int x, y, count = 0;
    while (n != 0)
    {
        x = va_arg(p, int);
        y = va_arg(p, int);
        if (f(x, y, R)) count++;
        n--;
    }
    va_end(p);
    return count;
};

