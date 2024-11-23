#include <iostream>


using namespace std;
int main()
{
	int N;
	cin >> N;
	int f = 1, *ptr = &f;
	for(int i = 2; i <= N; i++)
	{
		*ptr *= i;
	}
	cout << f;
	return 0;
}

