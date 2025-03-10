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
        for(int j = 0; j < size - i - 1; j++) {
            if(a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for(int i = 0; i < size; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}

