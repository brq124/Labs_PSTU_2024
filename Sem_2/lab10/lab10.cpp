#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int size;
	cout << "������� ������ �������" << endl;
	cin >> size;
	string* a = new string[size];
	cout << "������� " << size << " �����" << endl;
	cin >> ws;
	for (int i = 0; i < size; i++)
	{
		getline(cin, a[i]);
	}
	int idx = -1;
	for (int i = 0; i < size; i++)
	{
		if (a[i].back() == 'A' && a[i].front() == 'A')
		{
			idx = i;
			size--;
			break;
		}
	}
	if (idx != -1)
	{
		for (int i = idx; i < size - 1; i++)
		{
			a[i] = a[i + 1];
		}
	}
	cout << "������ ����� ������� �������� ��������:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << endl;
	}

	delete[] a;
	return 0;
}
