#include <iostream>

using namespace std;
int main()
{
	int n;
	float x, sum, f;
	cin >> n >> x;
	sum = 1 + x;
	f = 1;
	for (int i = 2; i <= n; i++)
	{
		f *= i;
		sum += pow(x, i) / f;
	}
	cout << sum;
	return 0;
}

