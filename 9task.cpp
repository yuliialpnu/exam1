#include<iostream>
#include <cstring>
#include<Windows.h>
#pragma warning(disable:4996)
using namespace std;
const int size1 = BUFSIZ;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "ukr");
    int in = 0, out = 0, len1, p = 0;
    char sub_str[100][100] = { 0 };
    char str[size1];
    char ch[size1];
    cout << "Введіть текст:";
    cin.getline(str, size1);
    cout << "Введіть буквосполучення:";
    cin.getline(ch, size1);
    while (str[p] != '\0')
    {
        out = 0;
        while (str[p] != ' ' && str[p] != '\0')
        {
            sub_str[in][out] = str[p];
            p++;
            out++;
        }
        sub_str[in][out] = '\0';
        in++;
        if (str[p] != '\0')
        {
            p++;
        }
    }
    int len = in;
    cout << "Усі слова що закінчуються буквосполученням " << ch << " :\n";

    for (in = 0; in < len; in++)
    {
        len1 = strlen(sub_str[in]);
        if (sub_str[in][len1 - 1] == *ch)
        {
            cout << sub_str[in] << " ";
        }
    }
}