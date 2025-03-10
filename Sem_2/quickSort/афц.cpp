#include <iostream>

void quickSort(int* a)
{
    quickSortRecursion
}

void quickSortRecursion(int* a, startIndex, int endIndex)
{
    for (int i = 0; i < endIndex; i++)
    {
        if (a[i] < a[endIndex - 1])
        {

        }
    }
}


using namespace std;
int main() {
    const int size = 10;
    int a[size];
    int range_min = -100, range_max = 100;
    for(int i = 0; i < size; i++) {
        a[i] = ((double)rand() / RAND_MAX) * (range_max - range_min) + range_min;
    }
    for(int i = 0; i < size; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    





    for(int i = 0; i < size; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}

