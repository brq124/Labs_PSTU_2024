#include <iostream>


using namespace std;
int main()
{
	int N;
	cin >> N;
	if (N > 0 && N == pow(sqrt(N), 2))
	{
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
		cout << "������� ������ N (������ ���� ������ ���������)" << endl;
	}
	return 0;
}