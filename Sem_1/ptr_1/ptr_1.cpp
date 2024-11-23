#include <iostream>

using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b;
	int *ptr1 = &a, *ptr2 = &b, *ptr3 = &c;
	*ptr3 = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = *ptr3;

	cout << a << " " << b;
	return 0;
}

