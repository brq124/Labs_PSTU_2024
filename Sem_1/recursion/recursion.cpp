// Рекурсия
// Найти позицию искомого значения в упорядоченном списке чисел
#include <iostream>
using namespace std;

int f(int arr_size, int *arr, int r, int pos)
{
	if (arr[pos] == r) return pos + 1;
	else if (pos + 1 == arr_size) return -1;
	else return f(arr_size, arr, r, ++pos);
}

int main()
{
	const int arr_size = 5;
	int arr[arr_size];
	for (int i = 0; i < arr_size; i++)
	{
		cin >> arr[i];
	}
	int r;
	cin >> r;
	cout << f(arr_size, arr, r, 0);
	return 0;
}

