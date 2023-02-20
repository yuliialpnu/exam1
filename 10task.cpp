// 10. Підрахувати число латинських букв на сторінці тексту, введеному як масив стрічок.

#include<iostream>
#include<cstring>
using namespace std;
const int s_len = 100;
int main()
{
    char* arr_ptr;
    char c;
    int alp = 0;
    char arr[s_len + 1];
    

    cout << " Count the letters in string:\n";
    cout << endl;
    cout << " Enter a string: ";
    cin.getline(arr, s_len + 1);
    cout << endl;
    for (arr_ptr = arr; *arr_ptr != '\0'; arr_ptr++)
    {
        c = *arr_ptr;
        if (isalpha(c))
        {
            alp++;
        }
    }
        cout << "Number of letters in string \"" << arr << "\" is = " << alp;
	return 0;
}