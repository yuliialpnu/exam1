// 12. Книжковий каталог бібліотеки зберігається у вигляді масиву структур, де вказано назву книги, автора, рік видання, жанр.
//Визначити, скільки детективів є в бібліотеці.


#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

const int s_len = 50;

struct book
{
	char name[s_len + 1];
	char author[s_len + 1];
	char genre[s_len + 1];
	int year;
	void input_data();


};
int enter_number(const char*);
void find_detective(book*& arr, int&);

int main()
{
	int n = 0;
	cout << "Welcome to the program!" << endl;
	book* arr = NULL;
	find_detective(arr, n);
	cout << "\nNumber of detectives in the library is \n" << n;

	delete[] arr;
	cout << "End of program!";
	return 0;

}

void book::input_data()
{
	cout << "Enter name of the book: ";
	cin.getline(name, s_len);
	cout << "Enter author: ";
	cin.getline(author, s_len);
	cout << "Enter genre of the book: ";
	cin.getline(genre, s_len);
	year = enter_number("year of publishing");
	while (year > 2023 || year < 0) year = enter_number("correct year of publishing");

}
void find_detective(book*& arr, int& n)
{
	int size;
	size = enter_number("amount of books in the library");
	arr = new book[size];

	for (int i = 0; i < size; i++)
	{
		cout << "\nInput next book: \n";
		(arr + i)->input_data();
		if ((strcmp((arr + i)->genre, "detective")) == 0) n++;
	}
}


int enter_number(const char* msg)
{
	cout << "Enter " << msg << ": ";
	const int len = 6;
	char* str = new char[len + 1];
	cin.getline(str, len);
	return atoi(str);
}

