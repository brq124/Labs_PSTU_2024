#include <iostream>

using namespace std;
int main()
{
	int N, K, S;
	bool flag = false;
	cin >> N >> S;
	while (N > 0 && !flag)
	{
		K = N % 10;
		if (K == S) flag = true;
		else N /= 10;
	}
	if (flag) cout << "Öטפנא םאיהוםא!";
	else cout << "Öטפנא םו םאיהוםא!";
	return 0;
}
