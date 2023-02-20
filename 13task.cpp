//13. Масив структур містить десять наборів із трьох чисел. Встановити, які з цих наборів є
// довжинами сторін трикутника, та обчислити їх периметр.
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

const int max_size = 3;

struct dano
{
	double a;
	double b;
	double c;
	void input_data();
	void print();
	bool is_triangle();



};
double enter_number(const char*);
void print(dano* arr);
int main()
{
	int n = 0;
	cout << "Welcome to the program!";
	dano* arr = new dano[max_size];
	print(arr);

	cout << "\nEnd of program!";
	return 0;

}

void dano::input_data()
{
	a = enter_number("first number");
	b = enter_number("second number");
	c = enter_number("third number");
}
void dano::print()
{
	cout << "\nFirst side of the triangle = " << a;
	cout << "\nSecond side of the triangle = " << b;
	cout << "\nThird side of the triagle = " << c;
	cout << "\nPerimetr of the triangle = " << a + b + c;
}
bool dano::is_triangle()
{
	if (a + b > c && b + c > a && a + c > b) {
		return true;
	}
	else {
		return false;
	}
}

void print(dano* arr)
{
	for (int i = 0; i < max_size; i++) {
		cout << "Input a new one: " << endl;
		(arr + i)->input_data();
	}
	cout << endl << "Result : " << endl;
	for (int i = 0; i < max_size; i++) {
		if (((arr + i)->is_triangle()) == true) {
			cout << "\n#" << i << endl;
			(arr + i)->print();
			cout << endl << endl;
		}
	}
}

double enter_number(const char* msg)
{
	cout << "Enter " << msg << ": ";
	const int s_len = 6;
	char* str = new char[s_len + 1];
	cin.getline(str, s_len);
	return atof(str);
}

