// Метод Половинного Деления
// sqrt(1 - 0.4 * pow(x, 2)) - asin(x)
// Отрезок, содержащий корень: [0; 1]
#include <iostream>

using namespace std;
int main()
{
	double a = 0, b = 1;
	double c;
	double e = 0.000001;
	while (b - a > e)
	{
		c = (a + b) / 2;
		double fa = sqrt(1 - 0.4 * pow(a, 2)) - asin(a);
		double fb = sqrt(1 - 0.4 * pow(b, 2)) - asin(b);
		double fc = sqrt(1 - 0.4 * pow(c, 2)) - asin(c);
		if (fa * fc < 0) b = c;
		else if (fb * fc < 0) a = c;
	}
	cout << "The root of the equation is " << (a + b) / 2;
	return 0;
}

