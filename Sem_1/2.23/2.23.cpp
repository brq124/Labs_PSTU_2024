#include <iostream>

using namespace std;
int main()
{
	float n, a;
	cin >> n;
	int max = sin(n + 1 / n), count = 1;
	for (int i = 2; i <= n; i++)
	{
		a = sin(n + i / n);
		if (a > max)
		{
			max = a;
			count = 1;
		}
		else if (a == max)
		{
			count++;
		}
	}
	cout << max << " " << count;
	return 0;
}
