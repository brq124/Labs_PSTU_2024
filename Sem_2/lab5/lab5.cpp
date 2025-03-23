#include <iostream>
using namespace std;

bool f(char* str, int N);

int main()
{
    setlocale(LC_ALL, "ru");
    const int N = 4;
    //char s[] = "725612923";
    char s[] = "7251691761789235";
    if (f(s, N)) cout << "Да";
    else cout << "Нет";
    return 0;
}

bool f(char* str, int N) // ,5,62 ,7,82 ,9,82
{
    for (int i = 0; i < pow(N, 2); i += N)
    {
        for (int j = i + N; j < pow(N, 2); j += N)
        {
            if (str[i] == str[j]) return false;
        }
    };
    return true;
}

