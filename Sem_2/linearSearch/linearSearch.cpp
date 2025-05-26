#include <iostream>
using namespace std;

int linearSearch(int* arr, int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == x) return i;
	}
	return -1;
}

int main()
{
	const int size = 10;
	int a[size] = { 4, 2, 6, 1, 7, 3, 5, 2, 8, 3 };
	cout << linearSearch(a, size, 7);
	return 0;
}

