// Метод Ньютона
// sqrt(1 - 0.4 * pow(x, 2)) - asin(x)
// Отрезок, содержащий корень: [0; 1]

#include <iostream>
using namespace std;
const double e = 0.000001;

double f(double x)
{
	return sqrt(1 - 0.4 * pow(x, 2)) - asin(x);
}

double df(double x)
{
	return -((2 * x) / (5 * sqrt(1 - (2 * pow(x, 2)) / 5)) - 1 / sqrt(1 - pow(x, 2)));
}

int main()
{
	double a = 0, b = 1;
	double x = a, x0;
	while (b - a > e)
	{
		x = x - (f(x) / df(x));
	}
	cout << "The root of the equation is " << x;
	return 0;
}

