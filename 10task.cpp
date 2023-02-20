// 10. Підрахувати число латинських букв на сторінці тексту, введеному як масив стрічок.

#include <iostream>
#include <cstring>

using namespace std;

const int s_len = 100;

int main() {
    const char* arr_ptr;
    char arr[s_len + 1];
    int alp = 0;

    cout << "Count the letters in string:" << endl;
    cout << "Enter a string: ";
    cin.getline(arr, s_len + 1);

    for (arr_ptr = arr; *arr_ptr != '\0'; arr_ptr++) {
        if (isalpha(*arr_ptr)) {
            alp++;
        }
    }
	
    cout << "Number of letters in string \"" << arr << "\" is = " << alp << endl;

    return 0;
}
