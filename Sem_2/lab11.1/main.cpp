#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	List list;
	int N;
	cout << list;
	cout << "������� ���������� ��������� ������:" << endl;
	cin >> N;
	char s[100];
	for (int i = 1; i <= N; i++)
	{
		cout << "������� " << i << " ������:" << endl;
		cin >> ws;
		cin.getline(s, 100);
		list.push_back(s);
	}
	cout << "������: " << list << endl << endl;

	int K, n;
	cout << "������� ����� K:" << endl;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cout << "������� ������� � �������:" << endl;
		cin >> n;
		list.erase(n-1);
	}
	cout << "������: " << list << endl;

	for (int i = 1; i <= K; i++)
	{
		cout << "������� " << i << " ������:" << endl;
		cin >> ws;
		cin.getline(s, 100);
		list.push_front(s);
	}
	cout << "������: " << list << endl;
	return 0;
}

