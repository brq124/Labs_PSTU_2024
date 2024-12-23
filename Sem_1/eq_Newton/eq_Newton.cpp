// Метод Ньютона
// pow(exp(1), x) - pow(exp(1), -x) - 2
// Отрезок, содержащий корень: [0; 1]
#include <iostream>

using namespace std;
int main()
{
	double x = 1, xPrev = 0;
	double e = 0.000001;
	while (abs(x - xPrev) > e)
	{
		xPrev = x;
		x = xPrev - ((pow(exp(1), x) - pow(exp(1), -x) - 2) /
			(pow(exp(1), x) + pow(exp(1), -x)));
	}
	cout << "The root of the equation is " << x;
	return 0;
}

