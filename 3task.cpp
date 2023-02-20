// 3. Заданий масив з N дійсних чисел.Записати в цей же масив спочатку всі додатні елементи, потім всі від’ємні, а потім нулі, зберігаючи порядок їх слідування.
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int* arr;
    arr = new int[n];
    cout << "Enter array: " << endl;
    for (int i = 0; i < n; i++) cin >> *(arr + i);
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            for (int j = 0; j < i; j++) {
                if (arr[j] > 0) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    delete[] arr;
    return 0;
}