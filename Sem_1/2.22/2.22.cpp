#include <iostream>

using namespace std;
int main()
{
	float n, a;
	cin >> n;
	int max = sin(n + 1 / n), num = 1;
	for (int i = 2; i <= n; i++)
	{
		a = sin(n + i / n);
		if (a > max)
		{
			max = a;
			num = i;
		}
	}
	cout << max << " " << num;
	return 0;
}
