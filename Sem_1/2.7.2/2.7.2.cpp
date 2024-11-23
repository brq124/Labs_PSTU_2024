#include <iostream>


using namespace std;
int main()
{
	int N;
	cin >> N;
	if (N > 0)
	{
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
		cout << "Неверно указан N (должен быть > 0)" << endl;
	}
	return 0;
}