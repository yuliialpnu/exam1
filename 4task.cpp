//4. Натуральне число N представити у вигляді масиву його цифр.

#include <iostream>
#include <string>
using namespace std;
const int N = 10;
typedef unsigned long long ull;

int digit(ull n, int, int arr[]);
double input_number(const char* msg);

int main()
{
	int m = 10, i = 0, arr[N];
	ull n = (ull)input_number("your number");
	digit(n, i, arr);
	return 0;
}
double input_number(const char* msg)
{
	cout << "Enter " << msg << ": ";
	char num[N + 1];
	cin.getline(num, N);
	return atof(num);
}

int digit(ull n, int i, int arr[])
{
	if (!n) {
		return 0;
	}
	else {
		do {
			int dig = (n % 10);
			arr[i] = dig;
			i++;
		}while (n /= 10);
	}
	for (int j = 0; j < i; j++) cout << arr[j] << " ";
}