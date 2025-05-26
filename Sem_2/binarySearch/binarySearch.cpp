#include <iostream>
using namespace std;

int binarySearch(int* arr, int low, int high, int x)
{
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (arr[mid] == x) return mid;
		else if (arr[mid] < x) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

int main()
{
	const int size = 10;
	int a[size] = { 1, 2, 2, 3, 3, 4, 5, 6, 7, 8 };
	cout << binarySearch(a, 0, size - 1, 7);
	return 0;
}

