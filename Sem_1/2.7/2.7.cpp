#include <iostream>

using namespace std;
int main()
{
	int N;
	cin >> N;
	if (N > 0 && N == pow(sqrt(N), 2))
	{
		cout << "1. " << endl;
		for (int i = 0; i < sqrt(N); i++)
		{
			for (int j = 0; j < sqrt(N); j++)
			{
				cout << '*';
			}
			cout << endl;
		}
	}
	else
	{
		cout << "1. Неверно указан N (должен быть полным квадратом)" << endl;
	}

	if (N > 0)
	{
		cout << "2. " << endl;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << '*';
			}
			cout << endl;
		}
	}
	else
	{
		cout << "2. Неверно указан N (должен быть > 0)" << endl;
	}

	if (N > 2)
	{
		cout << "3. " << endl;
		for (int i = 0; i < N; i++)
		{
			cout << '*';
		}
		cout << endl;
		for (int i = 0; i < N - 2; i++)
		{
			cout << '*';
			for (int j = 0; j < N - 2; j++)
			{
				cout << ' ';
			}
			cout << '*' << endl;
		}
		for (int i = 0; i < N; i++)
		{
			cout << '*';
		}
		cout << endl;
	}
	else
	{
		cout << "3. Неверно указан N (должен быть > 2)" << endl;
	}
	return 0;
}



