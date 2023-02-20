// 8. У введеному як масив стрічок тексті підрахувати число входжень букв ‘a’ та ‘А’.
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100;

int main() {
	char arr[N][N];

	int lines;
	cout << "Enter number of lines, you want to enter: ";
	cin >> lines;
	cout << endl << "Enter your lines:" << endl;
	char* ptr = arr[lines];
	for (int i = 0; i < lines; i++) {
		cin.getline(arr[i], N);
	}

	int times_a = 0;
	int times_A = 0;
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'a') {
				times_a++;
			}
			if (arr[i][j] == 'A') {
				times_A++;
			}
		}
	}
	cout << "Symbol a is entered " << times_a << " times. Symbol A is entered " << times_A << " times.";
	return 0;
}

bool SetAi(const char* str, int i)
{
	// Перевірка, чи індекс в допустимих межах
	if (CheckIndex(i))
	{
		// Звільнити попередньо виділену пам'ять для рядка A[i]
		if (A[i] != nullptr)
			delete[] A[i];

		// Скопіювати рядок: A[i] = str
		CopyStr(&A[i], str);

		return true;
	}
	return false;
}