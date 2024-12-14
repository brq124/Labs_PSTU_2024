#include <iostream>

using namespace std;
int main()
{
	int n, a, max;
	cin >> n >> max;
	for (int i = 2; i <= n; i++)
	{
		cin >> a;
		if (a > max) max = a;
	}
	cout << max;
	return 0;
}
