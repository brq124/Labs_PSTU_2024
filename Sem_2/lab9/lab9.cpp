#pragma warning(disable:4996)
#include <iostream>
using namespace std;

int find(char* str1, char* str2);

int main()
{
	setlocale(LC_ALL, "ru");

	FILE* f1 = fopen("F1.txt", "r");
	FILE* f2 = fopen("F2.txt", "w");

	char word[100];
	int i = 0;
	char c;
	while ((c = fgetc(f1)) != '\n')
	{
		word[i] = c;
		i++;
	}
	word[i] = '\0';

	char buf[100];
	while (fgets(buf, 100, f1) != NULL)
	{
		if (find(buf, word) == -1)
		{
			fputs(buf, f2);
		}
	}

	fclose(f1);
	fclose(f2);

	return 0;
}

int find(char* str1, char* str2) // нахождение индекса подстроки в строке
{
	if (strlen(str1) < strlen(str2)) return -1;
	int i = 0;
	while (str1[i] != '\0')
	{
		int j = 0;
		while (str1[i + j] == str2[j])
		{
			if (str2[j + 1] == '\0')
			{
				return i;
			}
			j++;
		}
		i++;
	}
	return -1;
}

