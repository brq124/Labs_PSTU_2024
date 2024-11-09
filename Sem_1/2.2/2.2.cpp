#include <iostream>

using namespace std;
int main()
{
	int N;
	cin >> N;
	int prod = 1;
	for (int i = 1; i <= N; i++)
	{
		prod *= i;
	}
	cout << prod;
	return 0;
}

