#include <iostream>
#include <cstdarg>
#define f(x, y, R) ((pow(x, 2) + pow(y, 2)) <= pow(R, 2))
using namespace std;

int belong(int R, int n, ...);

int main()
{
    setlocale(LC_ALL, "ru");
    const int R = 10;
    cout << "Первый вызов функции: " << belong(R, 1, 4, 6) << endl;
    cout << "Второй вызов функции: " << belong(R, 4, 7, 2, 8, 12, 1, 4, 8, 8) << endl;
    cout << "Третий вызов функции: " << belong(R, 9, 15, 2, 3, 16, 9, 4, 6, 2, 5, 2, 13, 7, 5, 3, 8, 6, 12, 9) << endl;
    return 0;
}

int belong(int R, int n, ...)
{
    va_list p;
    va_start(p, n);
    int x, y, count = 0;
    while (n != 0)
    {
        x = va_arg(p, int);
        y = va_arg(p, int);
        if (f(x, y, R)) count++;
        n--;
    }
    va_end(p);
    return count;
};

int sum(int n, int* p, ...)
{
    int result = 0;
    while (n != 0)
    {
        result += *p;
        p++;
        n--;
    }
    return result;
}
int sum(int n, ...)
{
    va_list p;
    va_start(p, n);
    int result = 0;
    while (n != 0)
    {
        result += va_arg(p, int);
        n--;
    }
    va_end(p);
    return result;
}

int* bucketSort(int arr[], int n)
{
    // для наглядности запишем кол-во ведер
    // и их размер прямо здесь, хотя их стоит вынести вне функции
    const int BUCKET_NUM = 10;
    const int BUCKET_SIZE = 10;
    int buckets[BUCKET_NUM][BUCKET_SIZE];
    // чтобы знать реальное число элементов в конкретном ведре и не вылезти за это число
    int bucketSizes[BUCKET_NUM] = { 0 };
    // раскидываем элементы массива по ведрам
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = arr[i] / BUCKET_NUM;
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }
    // сортируем каждое ведро
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        // берем сортировку вставками или любую другую
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            int tmp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > tmp)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = tmp;
        }
    }
    // складываем элементы в исходный массив
    int idx = 0;
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            arr[idx++] = buckets[i][j];
        }
    }
    return arr;
}


void shellSort(int arr[], int n)
{
    for (int h = n / 2; h > 0; h /= 2)
    {
        for (int i = h; i < n; i++)
        {
            int tmp = arr[i];
            for (int j = i; j >= h; j-=h)
            {
                if (tmp < arr[j - h])
                {
                    arr[j] = arr[j - h];
                }
                else break;
            }
            arr[j] = tmp;
        }
    }
}

