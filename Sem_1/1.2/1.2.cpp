#include <iostream>

using namespace std;
int main()
{
	double a, b;
	cin >> a >> b;
	if (b == 0)
	{
		cout << "На ноль делить нельзя!";
	}
	else
	{
		cout << a / b;
	}
	return 0;
}

