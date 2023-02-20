// 15. Інформація про стан здоров’я студентів групи зберігається у вигляді масиву структур.
// Медична картка студента містить інформацію про його прізвище, рік народження,
// ріст та вагу.Знайти найвищого і найважчого студентів групи.

#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

const int size = 30;

struct medical_card
{
	char last_name[size + 1];
	int year;
	double height;
	double weight;
	void input_data();


};
double enter_number(const char*);
void find_max_hw(medical_card* arr, int&, int&, int);
void input_arr(medical_card*& arr, int&);

int main()
{
	int max_height = 0, max_weight = 0;
	int n = 0;
	cout << "Welcome to the program!\n\n";
	medical_card* arr = NULL;
	input_arr(arr, n);
	find_max_hw(arr, max_height, max_weight, n);

	cout << "The highest student is " << (arr + max_height)->last_name << endl
		<< "The student with the biggest weight is " << (arr + max_weight)->last_name << endl;
	cout << "\nEnd of program!\n\n";
	return 0;

}

void medical_card::input_data()
{
	cout << "Enter last name of the student : ";
	cin.getline(last_name, size);
	year = (int)enter_number("year of birth");
	while (year > 2023 || year < 1) year = enter_number("correct year of birth");
	height = enter_number("height of the student");
	while (height <= 0) height = enter_number("correct height");
	weight = enter_number("weight of the student");
	while (weight <= 20) weight = enter_number("correct weight");

}
void input_arr(medical_card*& arr, int& n)
{
	n = (int)enter_number("number of students in the arr");
	arr = new medical_card[n];
	for (int i = 0; i < n; i++) {
		cout << "\nInput new medical card: \n";
		(arr + i)->input_data();
	}
}
void find_max_hw(medical_card* arr, int& max_height, int& max_weight, int n)
{
	for (int i = 1; i < n; i++) {
		if ((arr + i)->height > (arr + max_height)->height) max_height = i;
		if ((arr + i)->weight > (arr + max_weight)->weight) max_weight = i;
	}

}


double enter_number(const char* msg)
{
	cout << "Enter " << msg << ": ";
	const int Size = 5;
	char* str = new char[Size + 1];
	cin.getline(str, Size);
	return atof(str);
}
