#include <iostream>
#include <string>
#include <climits>
using namespace std;

int f(int* a, int size)
{
    if (size == 0) return 0;
    int min = a[0];
    for (int i = 0; i < size; i++)
    {
        if (a[i] < min) min = a[i];
    }
    return min;
}

int f(string s)
{
    int start = 0;
    int min_length = INT_MAX;
    for (int i = 0; i < s.length() + 1; i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            int word_length = i - start;
            if (word_length < min_length)
            {
                min_length = word_length;
            }
            start = i + 1;
        }
    }
    return min_length;
}

int main()
{
    setlocale(LC_ALL, "ru");
    const int size = 4;
    int a[size] = { 5, 2, 6, 4 };
    cout << "Минимальный элемент в массиве: " << f(a, size) << endl;
    string s = "Найти минимальное слово в предложении";
    cout << "Минимальная длина слова: " << f(s) << endl;
    return 0;
}

