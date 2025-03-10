#include <iostream>
using namespace std;

void countingSort(int* a, int size);

int main()
{
	setlocale(LC_ALL, "ru");
	const int size = 10;
	int a[size] = { 4, 2, 6, 1, 7, 3, 5, 2, 8, 3 };
	cout << "Массив до сортировки подсчетом: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	countingSort(a, size);
	cout << "Массив после сортировки подсчетом: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << ' ';
	}
	return 0;
}

void countingSort(int* a, int size)
{
	if (size < 2) return;
	int min, max;
	min = max = a[0];
	for (int i = 1; i < size; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		else if (a[i] > max)
		{
			max = a[i];
		}
	}

	int temp_size = max - min + 1;
	int* temp = new int[temp_size] {};
	for (int i = 0; i < size; i++)
	{
		temp[a[i]-min]++;
	}

	int i = 0;
	for (int j = 0; j < temp_size; j++)
	{
		for (int k = 0; k < temp[i]; k++)
		{
			a[i] = j + min;
			i++;
		}
	}
}

