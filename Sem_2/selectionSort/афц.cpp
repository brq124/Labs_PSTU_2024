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
    for(int i = 1; i < size; i++) {
        int key = a[i];
        int j = i;
        while(j > 0 && key < a[j-1]) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = key;
    }
    for(int i = 0; i < size; i++) {
        cout << a[i] << ' ';
    }
    return 0;
}

