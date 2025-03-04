#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "ru");
    const int size = 10;
    int a[size];
    int range_min = -100, range_max = 100;
    for (int i = 0; i < size; i++) {
        a[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
    }

    int K;
    cout << "¬ведите K в диапазоне [0; " << size - 1 << "]:" << endl;
    cin >> K;

    int i = K;
    do
    {
        cout << a[i] << ' ';
        i--;
        if (i < 0)
        {
            i = size - 1;
        }
    } while (i != K);
    cout << endl;

    int even_count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 == 0)
        {
            even_count++;
        }
    }
    int new_size = even_count + 2;
    int* b = new int[new_size];
    cout << "¬ведите первый и последний элементы:" << endl;
    cin >> b[0] >> b[new_size - 1];
    int k = 1;
    for (int i = 0; i < size - 1; i++)
    {
        if (a[i] % 2 == 0)
        {
            b[k] = a[i];
            k++;
        }
    }

    cout << "¬ведите K в диапазоне [0; " << new_size - 1 << "]:" << endl;
    cin >> K;
    i = K;
    do
    {
        cout << b[i] << ' ';
        i--;
        if (i < 0)
        {
            i = new_size - 1;
        }
    } while (i != K);
    delete[] b;
    return 0;
}

