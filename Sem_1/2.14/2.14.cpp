#include <iostream>

using namespace std;
int main()
{
	int N, S = 0;
	cin >> N;
	while (N > 0)
	{
		S += N % 10;
		N /= 10;
	}
	cout << S;
	return 0;
}
