#include<fstream>
#include<iostream>
using namespace std;
const char* file1 = "A.txt";//стрічки з іменемами файлу
const char* file2 = "B.txt";
const char* file3 = "C.txt";
const int size1 = 50;//розмірність
int main()
{
    int temp_1 = 0, temp_2 = 0, ptr = 0;//оголошення змінних
    int i = 0, j = 0;
    int arr_1[size1];//масиви у які будем зберігати 
    int arr_2[size1];
    ifstream Ain;//створення об'єкту потоку виводу для нового файлу з іменем Ain
    ofstream fout;//відкриття файлу для запису
    Ain.open(file1);
    if (!Ain.is_open()) {//якщо файл НЕ відкрито
        cout << "File " << file1 << " not found\n"; return 1;
    }
    ifstream Bin;
    Bin.open(file2);
    if (!Bin.is_open()) {//якщо файл НЕ відкрито
        cout << "File " << file2 << " not found\n"; return 1;
    }
    while (!Ain.eof())
    {
        while (Ain >> temp_1)// перевірка файла на спустошення  
        {
            arr_1[i] = temp_1;//записуємо цисла у масив
            i++;//лічильник для визначення розміру масиву
        }
    }
    int n;
    n = i;//розмір масиву 1
    while (!Bin.eof())
    {
        while (Bin >> temp_1)// перевірка файла на спустошення  
        {
            arr_2[j] = temp_1;//записуємо цисла у масив
            j++;//лічильник для визначення розміру масиву
        }
    }
    int m = j;//розмір масиву 2
    fout.open(file3);//звязування цього потоку з файлом file3 
    for (int i = 0; i < n; i++) {//цикл для знаходження різниці цих двох файлів
        ptr = 0;//прапорець
        for (int j = 0; j < m; j++) {
            if (arr_1[i] == arr_2[j]) { ptr = 1; }//якщо елементи рівні то  ptr = 1
        }
        if (ptr == 0) {//якщо  !ptr то записуємо значення у новий файл
            fout << arr_1[i] << " ";
        }
    }
    Ain.close();//закриття файлів
    Bin.close();
    fout.close();
    return 0;
}