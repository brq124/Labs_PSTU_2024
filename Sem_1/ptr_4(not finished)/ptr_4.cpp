#include <iostream>

using namespace std;
int main()
{
	int N;
	cin >> N;
	int a, *ptr = &a;
	cin >> a;
	int min = max = a;
	for (int i = 0; i < N; i++)
	{
		cin >> *ptr;
		if (*ptr < min)
		{
			min = *ptr;
		}
		else if (*ptr > max)
		{
			max = *ptr;
		}
	}
	return 0;
}

