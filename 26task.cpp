#include <iostream>
#include <fstream>

using namespace std;

void arithmetic_mean()
{

    ifstream file_stream("task27.txt");
    int num, sum;
    double amean = 0;

    if (!file_stream.is_open())
    {
        cout << "Failed to open the file";
        return;
    }

    while (file_stream >> num)
    {
        amean += num;
    }
    file_stream.close();
    cout << "SUM = " << amean;
    cout << "\nArithmetic_mean = " << amean / num << endl;
}

int main()
{
    arithmetic_mean();
    return 0;
}