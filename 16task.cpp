/*16. Визначити статистику оцінок, одержаних студентами групи 
(кількість п’ятірок,четвірок, трійок, двійок) під час сесії, 
якщо інформація про результати сесії зберігається у вигляді 
масиву структур, де вказано прізвище студента і його оцінки за
4 екзамени.*/
#include<iostream>
#include <iomanip>
using namespace std;
enum { finish, createarray, outputarray, sortArray };
const int s_len = 20, size_int = 4;

struct student
{
	char last_name[s_len];
	int marks[size_int];
	void input_data(const char*);
	void output_data(const char*);

};
void create_array(student*&, int&, const char*);
void output_array(student*, int, const char*);
void sort(student arr[], int, int, int, int, int);
int menu();
int enter_variant(student*&, int&, int);
int input_num(const char*);

int main()
{
	int n5 = 0, n4 = 0, n3 = 0, n2 = 0;
	student* arr;
	int n = 0, var;
	do {
		var = menu();
		var = enter_variant(arr, n, var);
	} while (var);
	cout << "end of program" << endl;
	return 0;

}
void create_array(student*& arr, int& n, const char* msg)
{
	cout << msg << endl;
	do {
		n = input_num(" number of students ");
	} while (n < 1);

	arr = new student[n];
	for (int i = 0; i < n; i++) arr[i].input_data("\nCurrent info about student\n");
}
void output_array(student* arr, int n, const char* msg)
{
	cout << msg << endl;
	if (!n) {
		cout << "Information absent\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i].output_data("\n");

	}
}
int menu()
{
	cout << "\nChoice variant of task\n";
	cout << createarray << " - Enter an array;" << endl;
	cout << outputarray << " - Show entered array;" << endl;
	cout << sortArray << " - Sort students;" << endl;
	cout << finish << " - or other - Exit;" << endl;

	return input_num("variant");
}
int input_num(const char* msg)
{
	cout << "Enter " << msg << " = ";
	const int s_len_ = 5;
	char number[s_len_ + 1];
	cin.getline(number, s_len_);
	return atoi(number);
}
int enter_variant(student*& arr, int& n, int k, int n5, int n4, int n3, int n2)
{


	switch (k)
	{
	case createarray:
		create_array(arr, n, "Created data about student\n");
		break;
	case outputarray:
		output_array(arr, n, "\nData about student\n");
		break;
	case sortArray:
		sort(arr, n, n5, n4, n3, n2);
		break;
	default:
		k = 0;
		break;

	}
	return k;
}
void sort(student arr, int n, int n5, int n4, int n3, int n2)
{
	if (!n) {
		cout << "Data about students absent\n";
		return;
	}
	student tnp;
	int flag = 1;
	while (flag && n)
	{
		flag = 0;
		n--;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 4; j++) {
				if (arr[i].marks[j] = 5) n5++;
				else if (arr[i].marks[j] = 4) n4++;
				else if (arr[i].marks[j] = 3) n3++;
				else if (arr[i].marks[j] = 2) n2++;
			}
		}
		cout << "Assessment statistics:\n" << " | " << n5 << "times students get 5 " << 
			" | " << n4 << "times students get 4 " <<
			" | " << n3 << "times students get 3 " <<
			" | " << n2 << "times students get 2 " << " | ";
	}
}

void student::input_data(const char* msg)
{
	cout << msg;
	cout << "Last name of student: ";
	cin.getline(last_name, s_len);
	for (int i = 0; i < size_int; i++) marks[i] = input_num("Marks of student");

	}

void student::output_data(const char* msg)
{
	cout << msg << endl;
	int p = 10;
	cout << "|Last name:" << setw(p) << last_name << " ";
	cout << " |Marks :" << marks << endl;
}
