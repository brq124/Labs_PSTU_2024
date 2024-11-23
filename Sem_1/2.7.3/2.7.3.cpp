#include <iostream>


using namespace std;
int main()
{
	int N;
	cin >> N;
	if (N > 2)
	{
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
		cout << "Неверно указан N (должен быть > 2)" << endl;
	}
}