#include <iostream>

using namespace std;
int main()
{
	int N;
	cin >> N;
	int S = 0;
	for (int i = 1; i <= N; i++)
	{
		int P = 1;
		for (int j = i; j <= i * 2; j++)
		{
			P *= j;
		}
		S += P;
	}
	cout << S;
	return 0;
}

