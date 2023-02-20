#include <iostream>
using namespace  std;
#pragma warning(disable:4996)
int size_file(FILE*, const char*); //встановлення кількості елементів у файлі
int from_file_to_array(FILE*, const char*, int*&, int&); //запис даних з файлу у масив
int creat_file(FILE*, const char*, int*&, int&);
int sort_array(int* a, int n);
int main()
{
    FILE* f = 0, * g = 0;
    const char* fn = "f.txt";
    const char* gn = "g.txt";
    int* a = 0;
    int n = 0, m = 0;
    int* b = 0;
    from_file_to_array(f, fn, a, n);
    from_file_to_array(g, gn, b, m);
    int* c = new int[n];
    bool prap = 0;
    int k = 0;
    //цикл знаходження перетину двох файлів
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                prap = 1; break;
            }
        }
        switch (prap) {
        case 1:c[k] = a[i]; k++; prap = 0; break;
        case 0:break;
        }
    }

    FILE* ff = 0;
    const char* ffn = "ff.txt";
    creat_file(f, ffn, c, k);
    delete[]c;
}

int size_file(FILE* f, const char* fn) //встановлення кількості елементів у файлі

{

    if ((f = fopen(fn, "r")) == NULL) //якщо файл не вдалося відкрити для читання

    {

        printf("\n File %s not found\n", fn);//друк повідомлення

        return 0; //повернення значення "невдача"

    }

    int n = 0, a; // n -- кількість елементів у файлі

    //a --цілочисельна змінна для зберігання потосного даного, зчитаного з файлу

    fscanf(f, "%d", &a); //введення даного з файлу

    while (!feof(f)) //поки не досягнуто кінця файлу

    {

        n++;

        fscanf(f, "%d", &a); //введення наступного даного з файлу

    }
    fclose(f); //закриття файлу

    return n ? n : -1;

    //повернення кількості елементів у файлі або -1, якщо файл порожній

}
int from_file_to_array(FILE* f, const char* fn, int*& a, int& n) //запис даних з файлу у масив
{
    if ((f = fopen(fn, "rb")) == NULL) //якщо файл не вдалося відкрити для читання
    {
        printf("\n File %s not found\n", fn);//друк повідомлення
        return 0; //повернення значення "невдача"
    }
    n = size_file(f, fn); //встановлення кількості елементів у файлі
    if (n <= 0) //якщо n -- некоректне
    {
        printf("\nFile %s is empty\n", fn); // друк повідомлення
        return 0; //повернення значення "невдача"
    }
    a = new int[n]; //виділення пам'яті під динамічний масив
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", a + i); //введення усіх даних з файлу у масив
    fclose(f); //закриття файлу
    return 1; //повернення значення "успіх"

}
int creat_file(FILE* f, const char* fn, int*& c, int& k) //функція заповнення файлу числами
{
    if ((f = fopen(fn, "w")) == NULL) //якщо файл не вдалося відкрити для запису
    {
        printf("\n Path to file %s not found\n", fn); //друк повідомлення
        return 0; //повернення значення "невдача"
    }
    sort_array(c, k);
    for (int i = 0; i < k; i++) //поки n не нуль
    {
        int a = c[i];
        fprintf(f, "%4d", a); //форматований запис числа у файл
        printf("%4d", a); //виведення числа на екран
    }
    printf("\n");
    fclose(f); //закриття файлу
    return 1; //повернення значення "успіх"
}
int sort_array(int* a, int n)
{
    int temp, flag = 1; // тимчасова зміння для обміну елементів масиву

    // Сортування методом бульбашки
    while (flag && n > 1) {
        flag = 0;
        n--;
        for (int j = 0; j < n; j++) {
            if (a[j] > a[j + 1]) {
                // міняємо елементи місцями
                flag = 1;
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    return 1; //повернення значення "успіх"
}