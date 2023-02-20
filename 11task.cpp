/*11. У гаражі є 10 автомобілів, інформація про які зберігається у вигляді масиву структур.
Відомості про авто містять його марку, прізвище власника, колір та рік випуску.
Вивести дані про автомобілі, старші п’яти років.*/


#include<iostream>
#include<iomanip>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

const int MAX_SIZE = 30;
enum { finish, createArray, outputArray, analise };
struct car
{
	char mark[MAX_SIZE + 1];
	char surname[MAX_SIZE + 1];
	char color[MAX_SIZE + 1];
	int year;
	void input_data(const char*);
	void output_data(const char*);
};
void create_array(car*&, int&, const char*);
void output_array(car*, int, const char*);
int menu();
void analise_cars(car* arr, int);
int enter_number(const char*);
int enter_var(car*&, int&, int);

int main()
{
	car* arr = 0;
	int n = 10, var;
	do {
		var = menu();
		var = enter_var(arr, n, var);
	} while (var);
	cout << "\n\nEnd of program!";
	return 0;
}

void car::input_data(const char* msg)
{
	cout << "Enter mark: ";
	cin.getline(mark, MAX_SIZE);
	cout << "Enter surname of the owner: ";
	cin.getline(surname, MAX_SIZE);
	cout << "Enter color : ";
	cin.getline(color, MAX_SIZE);
	year = enter_number("year of creating");
}

void car::output_data(const char* msg)
{
	cout << msg;
	int p = 10;
	cout << "|Mark:" << setw(p) << mark << " ";
	cout << "|Surnme of owner :" << setw(p) << surname << " ";
	cout << "|Color :" << setw(p) << color << " ";
	cout << " |Year :" << year << endl;
}

void create_array(car*& arr, int& n, const char* msg)
{
	cout << msg;
	arr = new car[n];
	for (int i = 0; i < n; i++) {
		arr[i].input_data("\nCurrent info about car\n");
	}
}

void output_array(car* arr, int n, const char* msg)
{
	cout << msg;
	for (int i = 0; i < n; i++) {
		arr[i].output_data("\n");
	}
}

int menu()
{
	cout << "\nChose variant of task\n";
	cout << createArray << " - Enter an information about cars;" << endl;
	cout << outputArray << " - Show entered inform;" << endl;
	cout << analise << " - Find worker by expiriace;" << endl;
	cout << finish << " - or other - Exit;" << endl;

	return enter_number("variant");
}

void analise_cars(car* arr, int n)
{
	int flag = 0, prokat, m = 5;
	cout << "/nCars, made earlier then 5 years ago: \n";
	for (int i = 0; i < n; i++) {
		prokat = (2023 - arr[i].year);

		if (prokat > m) {
			flag = 1;
			arr[i].output_data("\n");
		}
	} if (flag == 0) {
		cout << "There aren't sutiable cars\n";
	}
}

int enter_number(const char* msg)
{
	cout << "Enter " << msg << " = ";
	const int s_len = 5;
	char num[s_len + 1];
	cin.getline(num, s_len);
	return atoi(num);
}

int enter_var(car*& arr, int& n, int k)
{
	switch (k)
	{
	case createArray:
		create_array(arr, n, "Created data about cars: \n");
		break;
	case outputArray:
		output_array(arr, n, "Data about cars: \n");
		break;
	case analise:
		analise_cars(arr, n);
		break;
	default:
		k = 0;
		break;
	}
	return k;
}