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

    int new_size = 12;
    int b[12];
    cout << "¬ведите первый и последний элементы:" << endl;
    cin >> b[0] >> b[new_size - 1];
    for (int i = 0; i < size; i++)
    {
        b[i + 1] = a[i];
    }
    for (int i = 1; i < new_size - 1; i++)
    {
        if (b[i] % 2 != 0)
        {
            for (int j = i; j < new_size - 1; j++)
            {
                b[j] = b[j + 1];
            }
            new_size--;
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
    /*
    cout << endl << "============TEST===============================" << endl;
    for (int i : a) cout << i << " ";
    cout << endl;
    for (int i : b) cout << i << " ";
    cout << "==============" << endl;
    */
    return 0;
}

