#include <iostream>
#include <string>

using namespace std;
int main()
{
	char vowels[] = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};
	char consonants[] = {'�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};
	string str;
	getline(cin, str);
	int vowel_count = 0, consonant_count = 0;
	for (char c : str)
	{
		for (char vowchar : vowels)
		{
			if (c == vowchar) vowel_count++;
		}
		for (char conchar : consonants)
		{
			if (c == conchar) consonant_count++;
		}
	}
	cout << vowel_count << " " << consonant_count;
	return 0;
}

