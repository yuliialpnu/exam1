#include <iostream>
#include <string.h>
#include<stdio.h> //заголовковий файл з функціями для роботи з файлами у С
#include<time.h>
using namespace std;
#pragma warning(disable:4996)
#pragma warning(disable:6031)
enum { vybir_QUIT, vybir_create_files, vybir_use_existing_files, vybir_do_merging_files };

int MENU();
int creat_file(FILE*, const char*); //функція заповнення файлу числами
int show_file(FILE*, const char*, const char*); // друк вмістимого файлу на екран
int size_file(FILE*, const char*); //встановлення кількості елементів у файлі
int from_file_to_array(FILE*, const char*, int*&, int&); //запис даних з файлу у масив
int sort_array(int*, int);
int fill_file(FILE*, const char*, int*, int);
int union_orders_file(const char*, const char*, const char*);
double enter_number();

int MENU()
{
    int vybir;
    cout << "\n\tMENU\n"
        << vybir_create_files << ". Create new input files.\n"
        << vybir_use_existing_files << ". Show and sort (if needed) existing input files.\n"
        << vybir_do_merging_files << ". Do merging of input files.\n"
        << vybir_QUIT << ". 0 or something else - end of program.\n";
    vybir = enter_number();
    return vybir;
}

int show_file(FILE* f, const char* fn, const char* msg) //друк вмістимого файлу на екран
{
    if ((f = fopen(fn, "r")) == NULL) //якщо файл не вдалося відкрити для читання
    {
        printf("\n File %s not found\n", fn); //друк повідомлення
        return 0; //повернення значення "невдача"
    }
    puts(msg);
    puts(fn); //друк на екран імені файлу
    /*char ch;
    while ((ch = fgetc(f)) != EOF) {
        printf("%c", ch);
    }*/
    int a; //цілочисельна змінна для зберігання поточного даного, зчитаного з файлу
    fscanf(f, "%d", &a); //введення даного з файлу
    while (!feof(f)) //поки не досягнуто кінця файлу
    {
        printf("%5d ", a); //друк даного на екрані
        fscanf(f, "%d", &a); //введення наступного даного з файлу
    }
    puts("\n");
    fclose(f); //закриття файлу
    return 1; //повернення значення "успіх"
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
    //повернення або кількості елементів у файлі, або -1, якщо файл порожній
}

int from_file_to_array(FILE* f, const char* fn, int*& a, int& n) //запис даних з файлу у масив
{
    int i, k = 0;
    if ((f = fopen(fn, "r")) == NULL) //якщо файл не вдалося відкрити для читання
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

    a = new int[n];
    for (i = 0; i < n; i++)
    {
        fscanf(f, "%d", a + i);
    }

    fclose(f); //закриття файлу
    return 1; //повернення значення "успіх"
}

int sort_array(int* a, int n)
{
    int temp, flag = 1; // тимчасова зміння для обміну елементів масиву


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
int fill_file(FILE* f, const char* fn, int* a, int n)
{
    f = fopen(fn, "w");
    if (!f) {
        printf("Path to file %s not found\n", fn);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d  ", a[i]);
    }
    fprintf(f, "\n");

    fclose(f);
    return 1;

}

int union_orders_file(const char* fn1, const char* fn2, const char* fn3)
{
    FILE* f = fopen(fn1, "r");
    if (!f) {
        printf("\n File %s not found\n", fn1); //друк повідомлення
        return 0; //повернення значення "невдача"
    }
    FILE* g = fopen(fn2, "r");
    if (!g) {
        printf("\n File %s not found\n", fn2); //друк повідомлення
        return 0; //повернення значення "невдача"
    }

    FILE* h = fopen(fn3, "w");
    if (!h) {
        printf("\n Path to file %s not found\n", fn3); //друк повідомлення
        return 0; //повернення значення "невдача"
    }

    int a, b, c;
    fscanf(f, "%d", &a);
    fscanf(g, "%d", &b);
    while (!feof(f) && !feof(g)) {
        if (a < b) {
            c = a;
            fscanf(f, "%d", &a);
        }
        else {
            c = b;
            fscanf(g, "%d", &b);
        }
        fprintf(h, "%5d ", c);
    }
    for (; !feof(f);) {
        fprintf(h, "%5d ", a);
        fscanf(f, "%d", &a);
    }
    for (; !feof(g);) {
        fprintf(h, "%5d ", b);
        fscanf(g, "%d", &b);
    }
    fcloseall();
    return 1;
}


int creat_file(FILE* f, const char* fn) //функція заповнення файлу числами
{
    if ((f = fopen(fn, "w")) == NULL) //якщо файл не вдалося відкрити для запису
    {
        printf("\n Path to file %s not found\n", fn); //друк повідомлення
        return 0; //повернення значення "невдача"
    }
    int n, max_value;
    do
    {
        printf("\n Enter count of numbers in file %s n = ", fn);
        scanf("%d", &n); //введення кількості чисел для запису у файл
    } while (n <= 0); //перевірка коректності введеного даного
    printf("\n Enter max value of numbers = ");
    scanf("%d", &max_value); //введення параметру для генерування випадкових чисел
    max_value = abs(max_value);
    if (!max_value) //перевірка коректності введених даних (не нуль) 
        max_value = 100;
    for (; n; n--) //поки n не нуль
    {
        int a = rand() % (max_value + 1) - max_value / 2; //генерування числа
        fprintf(f, "%5d ", a); //форматований запис згенерованого числа у файл
        //printf("%5d", a); //виведення згенерованого числа на екран
    }

    fclose(f); //закриття файлу
    return 1; //повернення значення "успіх"
}

double enter_number()
{
    char res[BUFSIZ + 1];
    cout << "\nEnter number of choice: ";
    cin >> res;
    return atof(res);
}
int main() {
    FILE* f = 0, * g = 0, * ff = 0;
    const char* f_name = "f.txt";
    const char* g_name = "g.txt";
    const char* ff_name = "ff.txt";
    int* a = 0, size1 = 0;//a -- ім'я масиву, size1 --розмірність масиву
    int* b = 0, size2 = 0;
    int* c = 0, size3 = 0;
    srand(unsigned(time(0)));
    int vybir;
    do {
        vybir = MENU();
        switch (vybir)
        {
        case vybir_create_files:
            if (!creat_file(f, f_name)) //якщо файл не вдалося створити -- "невдача"
            {
                printf("\n File %s not created\n", f_name); //друк повідомлення
                return 1;
            }
            if (!creat_file(g, g_name)) //якщо файл не вдалося створити -- "невдача"
            {
                printf("\n File %s not created\n", g_name); //друк повідомлення
                return 1;
            }
            break;

        case vybir_use_existing_files:
            if (!show_file(f, f_name, "\n\nFile before sorting:"))
                // якщо друк вмістимого файлу на екран НЕ відбувся
            {
                printf("\n File %s no show\nend\n", f_name);
                return 1;
            }
            if (!from_file_to_array(f, f_name, a, size1))
                //якщо запис даних з файлу у масив НЕ відбувся
            {
                printf("\nNo copy to file\nend\n");
                return 1;
            }
            if (!sort_array(a, size1)) {
                printf("\nArray wasn't sorted\nend\n");
                return 1;
            }
            if (!fill_file(f, f_name, a, size1)) {
                printf("\nThe file could not be filled\nend\n");
                return 1;
            }

            if (size1) //якщо масив непорожній
            {
                delete[] a; //звільнення пам'яті
            }

            if (!show_file(f, f_name, "\n File after sorting:"))
                /*якщо друк вмістимого файлу на екран НЕ відбувся*/
            {
                printf("\n File %s no show\nend\n", f_name);
                return 1;
            }
            if (!show_file(g, g_name, "\n\nFile before sorting:"))
                // якщо друк вмістимого файлу на екран НЕ відбувся
            {
                printf("\n File %s no show\nend\n", g_name);
                return 1;
            }

            if (!from_file_to_array(g, g_name, b, size2))
                //якщо запис даних з файлу у масив НЕ відбувся
            {
                printf("\nNo copy to file\nend\n");
                return 1;
            }
            if (!sort_array(b, size2)) {
                printf("\nArray wasn't sorted\nend\n");
                return 1;
            }
            if (!fill_file(g, g_name, b, size2)) {
                printf("\nThe file could not be filled\nend\n");
                return 1;
            }

            if (size2) //якщо масив непорожній
            {
                delete[] b; //звільнення пам'яті
            }

            if (!show_file(g, g_name, "\n File after sorting:"))
                /*якщо друк вмістимого файлу на екран НЕ відбувся*/
            {
                printf("\n File %s no show\nend\n", g_name);
                return 1;
            }
            break;

        case vybir_do_merging_files:


            union_orders_file(f_name, g_name, ff_name);

            if (!show_file(ff, ff_name, "\n The result of merging two files:"))
                /*якщо друк вмістимого файлу на екран НЕ відбувся*/
            {
                printf("\n File %s no show\nend\n", ff_name);
                return 1;
            }

            fcloseall();
            break;
        default: vybir = vybir_QUIT;  break;
        }
    } while (vybir);

    cout << "\n\t END OF PROGRAM\n";
    system("pause");
    return 0;
}