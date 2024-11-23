#include <iostream>

using namespace std;
int main()
{
	int a;
	cin >> a;
	int *ptr = &a;
	cin >> *ptr;
	cout << a;
	return 0;
}

	