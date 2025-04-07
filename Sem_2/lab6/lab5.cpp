#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    string s = "3aweg 4abcabc 3g 5kekw) 4fff ad 3 6f affa3s 2";
    //getline(cin, s);
    s.insert(0, " ");
    int word_digit_count = 0;
    //if (s[0] >= '0' && s[0] <= '9') word_digit_count++;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == ' ' && s[i + 1] >= '0' && s[i + 1] <= '9')
        {
            word_digit_count++;
        }
    }
    string* words = new string[word_digit_count];
    int j = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == ' ' && s[i + 1] >= '0' && s[i + 1] <= '9')
        {
            while (s[i + 1] != ' ' && i < s.length() - 1)
            {
                i++;
                words[j] += s[i];
            }
            j++;
        }
    }
    for (int i = 0; i < word_digit_count - 1; i++)
    {
        for (int j = 0; j < word_digit_count - i - 1; j++)
        {
            if (words[j] < words[j + 1])
            {
                std::swap(words[j], words[j + 1]);
            }
        }
    }
    for (int i = 0; i < word_digit_count; i++)
    {
        cout << words[i] << endl;
    }
    return 0;
}

