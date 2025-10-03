#include <iostream>
using namespace std;

void hanoy(int n, char start, char buf, char point) {
    if (n == 1)
    {
        cout << "Диск 1: " << start << " --> " << point << endl;
        return;
    }
    hanoy(n - 1, start, point, buf); // hanoy(n - 1, start, buf, point);
    cout << "Диск " << n << ": " << start << " --> " << buf << endl;
    hanoy(n - 1, point, start, buf);
}

int main() {
    setlocale(LC_ALL, "ru");
    hanoy(3, 'A', 'C', 'B');
    return 0;
}

