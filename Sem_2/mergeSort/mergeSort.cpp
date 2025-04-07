#include <iostream>
using namespace std;

void mergeSort(int* a, int left, int right);
void merge(int* a, int left, int mid, int right);

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
    mergeSort(a, 0, size - 1);
    for(int i = 0; i < size; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}

void mergeSort(int* a, int left, int right)
{
    int mid = left + (right - left) / 2;
    if (left < right)
    {
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid + 1, right);
    }
}

void merge(int* a, int left, int mid, int right)
{
    int leftRange = mid - left + 1;
    int rightRange = right - mid;
    int* leftArr = new int[leftRange];
    int* rightArr = new int[rightRange];
    for (int i = 0; i < leftRange; i++)
    {
        leftArr[i] = a[left + i];
    }
    for (int i = 0; i < rightRange; i++)
    {
        rightArr[i] = a[mid + 1 + i];
    }

    int mergeIdx = 0;
    int leftIdx = 0, rightIdx = 0;
    while (leftIdx < leftRange && rightIdx < rightRange)
    {
        if (leftArr[leftIdx] < rightArr[rightIdx])
        {
            a[mergeIdx] = leftArr[leftIdx];
            leftIdx++;
        }
        else
        {
            a[mergeIdx] = rightArr[rightIdx];
            rightIdx++;
        }
        mergeIdx++;
    }

    while (leftIdx < leftRange)
    {
        a[mergeIdx] = leftArr[leftIdx];
        leftIdx++;
        mergeIdx++;
    }
    while (rightIdx < rightRange)
    {
        a[mergeIdx] = rightArr[rightIdx];
        rightIdx++;
        mergeIdx++;
    }

    delete[] leftArr;
    delete[] rightArr;
}


