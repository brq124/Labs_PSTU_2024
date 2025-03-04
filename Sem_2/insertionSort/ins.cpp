#include <iostream>

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
    int tmp;
    for(int i = 0; i < size - 1; i++) {
        int min_index = i;
        for(int j = i + 1; j < size; j++) {
            if(a[j] < a[min_index]) {
                min_index = j;
            }
        }
        tmp = a[i];
        a[i] = a[min_index];
        a[min_index] = tmp;
    }
    for(int i = 0; i < size; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}

