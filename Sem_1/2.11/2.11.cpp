#include <iostream>
using namespace std;

int main()
{
	int n, tmp;
	bool plusFirst = false;
	bool minusFirst = false;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (!plusFirst && !minusFirst)
		{
			if (tmp > 0) plusFirst = true;
			else if (tmp < 0) minusFirst = true;
		}
	}
	if (plusFirst) cout << "Сначала ввели положительное числа";
	else if (minusFirst) cout << "Сначала ввели отрицательные числа";
	else cout << "Все элементы были нулевыми";
	return 0;
}

