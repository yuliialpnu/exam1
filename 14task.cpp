//14. Результати метеорологічних спостережень за квітень зберігаються у вигляді масиву
// структур, де вказано день місяця, середньодобову температуру, % вологості, опади
// (дощ, сніг тощо).Визначити найхолодніший і найтепліший дні квітня.

#include<iostream>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

const int days = 30;

struct weather
{
	int day;
	double temp;
	double humidity;
	char prec[days + 1];

};
void find(weather arr[], int& hot, int& cold);

int main()
{
	int hot = 0, cold = 0;
	weather arr[30];
	find(arr, hot, cold);
	cout << "The coldest day is " << arr[cold].day << " of April.| The hottest day is " << arr[hot].day << " of April." << endl;
	cout << "End of program!";
	return 0;

}
void find(weather arr[], int& hot, int& cold)
{
	for (int i = 1; i < days; i++) {
		if (arr[i].temp > arr[hot].temp) {
			hot = i;
		}
		else if (arr[i].temp < arr[cold].temp) {
			cold = i;
		}
	}

}

