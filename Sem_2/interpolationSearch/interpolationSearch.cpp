#include <iostream>
using namespace std;

int interpolationSearch(int* arr, int low, int high, int x)
{
	while (low <= high && x >= arr[low] && x <= arr[high])
	{
		if (low == high)
		{
			if (arr[low] == x) return low;
			return -1;
		}
		int pos = low + (((x - arr[low]) * (high - low)) / (arr[high] - arr[low]));
		if (arr[pos] == x) return pos;
		else if (arr[pos] < x) low = pos + 1;
		else high = pos - 1;
	}
	return -1;
}

int main()
{
	const int size = 10;
	int a[size] = { 1, 2, 2, 3, 3, 4, 5, 6, 7, 8 };
	cout << interpolationSearch(a, 0, size - 1, 7);
	return 0;
}

