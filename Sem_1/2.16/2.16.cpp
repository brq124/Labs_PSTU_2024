#include <iostream>

using namespace std;
int main()
{
	int N, S = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		if (i % 2 == 0) S += i;
		else S -= i;
	}
	cout << S;
	return 0;
}
