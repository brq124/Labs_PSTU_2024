#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	List list;
	int N;
	cout << list;
	cout << "Введите количество элементов списка:" << endl;
	cin >> N;
	char s[100];
	for (int i = 1; i <= N; i++)
	{
		cout << "Введите " << i << " строку:" << endl;
		cin >> ws;
		cin.getline(s, 100);
		list.push_back(s);
	}
	cout << "Список: " << list << endl << endl;

	int K, n;
	cout << "Введите число K:" << endl;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cout << "Удаляем элемент с номером:" << endl;
		cin >> n;
		list.erase(n-1);
	}
	cout << "Список: " << list << endl;

	for (int i = 1; i <= K; i++)
	{
		cout << "Введите " << i << " строку:" << endl;
		cin >> ws;
		cin.getline(s, 100);
		list.push_front(s);
	}
	cout << "Список: " << list << endl;
	return 0;
}

