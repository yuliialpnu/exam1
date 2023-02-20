//7. У введеному як масив стрічок тексті підрахувати число слів.
#include <iostream>
#include <cstring>
using namespace std;

const int s_len = 100;
const int num = 10;

int main() {
	char arr[num][s_len];
	char line[s_len];
	int lines;

	cout << "Enter number of lines, you want to enter: ";
	cin >> lines;

	/*for (int i = 0; i < lines; i++) {
		cin.getline(line, (s_len+1));
		int len = line.lenght();
		arr[i][len] = line;
	}*/

	cout << endl << "Enter your lines:" << endl;
	char** ptr = new char* [lines];
	for (int i = 0; i < lines; i++) {
		arr[i] = cin.getline(line, (s_len + 1));
	}

	char rsd[] = " .,/\|?!@#$%^&*()_+-][{}';:<>";
	char** ptr;
	ptr = strtok(line, rsd);
	int nub_of_words = 0;

	for (int i = 0; i < s_len; i++) {
		if (line[i] == ' ') nub_of_words++;
	}
	cout << "Number of words: " << nub_of_words;

}