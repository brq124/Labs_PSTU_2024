#include <iostream>
#include <string>

using namespace std;
int main()
{
	string str;
	getline(cin, str);
	char c1, c2;
	cin >> c1 >> c2;
	int c1_count = 0, c2_count = 0, other_count = 0, all_char = 0;
	for (char c: str)
	{
		if (c == c1) c1_count++;
		else if (c == c2) c2_count++;
		else other_count++;
		all_char++;
	}
	cout << c1_count << " " << c2_count << " " << other_count << " " << all_char;
	return 0;
}
