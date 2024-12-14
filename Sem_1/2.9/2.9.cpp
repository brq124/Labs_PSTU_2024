#include <iostream>

using namespace std;
int main()
{
	int N;
	cin >> N;
	int h = N / 2;

	for (int i = 0; i < h; i++)
		cout << " ";
	for (int i = 0; i < N; i++)
		cout << "* ";
	cout << endl;

	for (int i = 0; i < h - 1; i++)
	{
		for (int j = 0; j < h - 1 - i; j++)
		{
			cout << " ";
		}
		cout << "* ";
		for (int j = 0; j < N - 2; j++)
		{
			cout << "  ";
		}
		cout << "*";
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		cout << "*" << endl;
	}

	for (int i = 0; i < N; i++)
		cout << "* ";
	for (int i = 0; i < h - 2; i++)
		cout << " ";
	cout << "*" << endl;

	for (int i = 0; i < h; i++)
	{
		cout << "* ";
		for (int j = 0; j < N - 2; j++)
			cout << "  ";
		cout << "*";

		for (int j = 0; j < h - 1; j++)
			cout << " ";
		cout << "*" << endl;
	}
	for (int i = 0; i < h; i++)
	{
		cout << "* ";
		for (int j = 0; j < N - 2; j++)
			cout << "  ";
		cout << "*";

		for (int j = 0; j < h - i - 1; j++)
			cout << " ";
		cout << "*" << endl;
	}

	for (int i = 0; i < N; i++)
		cout << "* ";

	return 0;
}

