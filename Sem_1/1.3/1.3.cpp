#include <iostream>

using namespace std;
int main()
{
	double a;
	cin >> a;
	if (a < 5)
	{
		a *= 3;
	}
	else if (a > 7)
	{
		a += 3;
	}
	else
	{
		a /= 10;
	}
	cout << a;
	return 0;
}

