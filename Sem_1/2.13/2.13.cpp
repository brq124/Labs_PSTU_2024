#include <iostream>

using namespace std;
int main()
{
	float a, b, c, D, x1, x2;
	cin >> a >> b >> c;
	D = pow(b, 2) - 4 * a * c;
	if (D > 0)
	{
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
		cout << x1 << " " << x2 << endl;
	}
	else if (D == 0)
	{
		x1 = (-b) / (2 * a);
		cout << x1 << endl;
	}
	else
	{
		cout << "Корней нет!" << endl;
	}
	return 0;
}

