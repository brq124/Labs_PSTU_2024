// Метод Итераций
// pow(exp(1), x) - pow(exp(1), -x) - 2
// Отрезок, содержащий корень: [0; 1]
#include <iostream>

using namespace std;
int main()
{
	double x = 1, xPrev = 0;
	double e = 0.000001;
	double l = -0.1;
	while (abs(x - xPrev) > e)
	{
		xPrev = x;
		x = l * (pow(exp(1), xPrev) - pow(exp(1), -xPrev) - 2) + xPrev;
	}
	cout << "The root of the equation is " << x;
	return 0;
}

