#include <iostream>

using namespace std;
int main()
{
	double a, b;
	cin >> a >> b;
	double *ptr1 = &a, *ptr2 = &b;
	cout << *ptr1 + *ptr2;
	return 0;
}

