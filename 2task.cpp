//2. Заданий двовимірний масив дійсних чисел з m стрічок та n стовпчиків. Впорядкувати масив по неспаданню елементів першого рядка.


#include <iostream>/*підключаю бібліотеки*/
using namespace std;
const int N = 10;

void sort_array(int arr[N][N], int cols);

int main() {
    int rows, cols;/*створюю тимчасову зміну*/
    int arr[N][N];/*створюю цикл*/
    cout << "enter num. of rows and colunbs:" << endl;
    cin >> rows;
    cin >> cols;


    sort_array(arr, cols);

    for (int i = 0; i < rows; i++) {/*виводжу на екран посортований масив*/
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void sort_array(int arr[N][N], int cols)
{
    int tmp;
    for (int i = 0; i < cols - 1; cols++) {
        if (arr[0][i] > arr[0][i + 1])
            tmp = arr[0][i];
        arr[0][i] = arr[0][i + 1];
        arr[0][i + 1] = tmp;
    }
}