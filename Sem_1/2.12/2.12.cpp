#include <iostream>

using namespace std;
int main()
{
	int n, a, min, max;
	cin >> n >> a;
	min = a;
	max = a;
	for (int i = 2; i <= n; i++)
	{
		cin >> a;
		if (a > max) max = a;
		else if (a < min) min = a;
	}
	cout << min + max;
	return 0;
}