#include <iostream>

using namespace std;
int main()
{
	double a, b;
	cin >> a >> b;
	int op;
	cin >> op;
	switch (op)
	{
	case 1:
		cout << a + b;
		break;
	case 2:
		cout << a - b;
		break;
	case 3:
		cout << a * b;
		break;
	case 4:
		if (b == 0)
		{
			cout << "На ноль делить нельзя!";
		}
		else
		{
			cout << a / b;
		}
		break;
	default:
		cout << "Неверный код операции!";
		break;
	}
	return 0;
}

