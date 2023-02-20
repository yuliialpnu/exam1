#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
typedef int dani; //дає типу int нове ім'я
const int size1 = 2, size2 = 2;
typedef dani matrix[size1][size2]; //новий тип користувача
int main()
{
    matrix a = { 0 };
    int n(size1), m(size2), value(20);
    srand(unsigned(time(0)));
    cout << "\nZhenerovana matrucia^\n";
    for (int i = 0; i < n; cout << "\n", i++)
        for (int j = 0; j < m; j++)
        {
            a[i][j] = rand() % (value + 1) - value / 2; //генерування елементів з діапазону [-10;10]
            cout.width(5);
            cout << a[i][j];
        }
    int i_min = 0, j_min;
    dani c;
    for (int i = 0; i < n; i++) //знаходження найменшого елемента у кожному рядку
    {
        int j_max = 0; //першим найменшим вибирається елемент першого стовпця
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] > a[i][j_max])
                j_max = j;
        }
        if (!i) //вибір першого максимума (нульового рядка)
        {
            c = a[0][j_max];
            j_min = j_max;
        }
        else
            if (a[i][j_max] < c)
            {
                c = a[i][j_max];
                j_min = j_max;
                i_min = i;
            }
    }
    cout << "\nc = min(max(a[i][j])) = a[" << i_min + 1 << "," << j_min + 1 << "] = "
        << c << "\n";
    return 0;
}