#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string s = "aweg weagaweg 5aegwaegwaeg 4 a s f affas";
    //getline(cin, s);
    int word_digit_count = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == ' ' && s[i+1] >= '0' && s[i + 1] <= '9')
        {
            word_digit_count++;
        }
    }
    string* a = new string[word_digit_count];
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == ' ' && s[i + 1] >= '0' && s[i + 1] <= '9')
        {
            word_digit_count++;
        }
    }
    return 0;
}

