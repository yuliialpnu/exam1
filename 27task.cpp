#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
using namespace std;

int input_numbers(const char* path);
int count_of_nambers(const char* path);
int get_numbers(const char* path, int arr[]);
int sort_numbres_to_file(const char* path, int arr[], int count);
int output_numbers(int arr[], int count);
void sort_numbers(int arr[], int count);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const char* path = "f.txt";
    input_numbers(path);
    int count = count_of_nambers(path);
    int* arr = new int[count];
    get_numbers(path, arr);
    sort_numbers(arr, count);
    sort_numbres_to_file(path, arr, count);
    output_numbers(arr, count);
    delete[] arr;
    system("pause");
    return 0;
}

int input_numbers(const char* path)
{
    int n;
    do
    {
        cout << "Введіть скільки хочете ввести чисел(0, якщо жодної): "; cin >> n;
    } while (n < 0);
    if (n == 0)
    {
        return 0;
    }
    ofstream fout(path, ios::app);
    if (!fout.is_open())
    {
        cout << "\nФайл не знайдено!" << endl;
        return 0;
    }
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cin.ignore();
        if (i != 0) { fout << ' '; }
        fout << x;
    }
    fout.close();
    return 0;
}

int count_of_nambers(const char* path)
{
    ifstream fin(path);
    if (!fin.is_open())
    {
        cout << "\nФайл не знайдено!" << endl;
        return 0;
    }
    int i = 0;
    char str[BUFSIZ];
    while (!fin.eof())
    {
        fin >> str;
        i++;
    }
    fin.close();
    fin.clear();
    return i;
}

int get_numbers(const char* path, int arr[])
{
    ifstream fin(path);
    if (!fin.is_open())
    {
        cout << "\nФайл не знайдено!" << endl;
        return 0;
    }
    int i = 0;
    char str[BUFSIZ];
    while (!fin.eof())
    {
        fin >> str;
        arr[i] = atoi(str);
        i++;
    }
    fin.close();
    return 0;
}

int sort_numbres_to_file(const char* path, int arr[], int count)
{
    ofstream fout(path);
    if (!fout.is_open())
    {
        cout << "\nФайл не знайдено!" << endl;
        return 0;
    }
    for (int i = 0; i < count; i++)
    {
        fout << arr[i];
        fout << " ";
    }
    fout.close();
    return 0;
}

int output_numbers(int arr[], int count)
{
    cout << "\nТак записано у файлі:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << arr[i];
        cout << " ";
    }
    cout << endl;
    return 0;
}

void sort_numbers(int arr[], int count)
{
    int temp;
    int n, m = count;
    while (m > 1)
    {
        m--;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}