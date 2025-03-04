#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    const int N = 3;
    std::string s = "725712923";
    //cout << "Введите строку длиной " << pow(N, 2) << ": ";
    //getline(cin, s);
    int mat[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            mat[i][j] = (int)(s[i * N + j] - '0');
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }

    bool f = true;
    for (int i = 0; i < N && f; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (mat[i][0] == mat[j][0])
            {
                f = false;
                break;
            }
        }
    };

    if (f) cout << "Да";
    else cout << "Нет";
    return 0;
}

