#include <iostream>
#include <string>

using namespace std;
int main()
{
	char vowels[] = {'à', 'å', '¸', 'è', 'î', 'ó', 'û', 'ý', 'þ', 'ÿ'};
	char consonants[] = {'á', 'â', 'ã', 'ä', 'æ', 'ç', 'é', 'ê', 'ë', 'ì', 'í', 'ï', 'ð', 'ñ', 'ò', 'ô', 'õ', 'ö', '÷', 'ø', 'ù'};
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

