#include <iostream>

using namespace std;
int main()
{
	int a, b;
	cin >> a;
	bool flag = true;
	while (a != 0)
	{
		cin >> b;
		if (b != 0 && a > b) flag = false;
		a = b;
	}
	if (flag)
	{
		cout << "Упорядочена";
	}
	else
	{
		cout << "Не упорядочена";
	}
	return 0;
}
