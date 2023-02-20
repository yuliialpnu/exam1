#include <iostream>
#include <fstream>


using namespace std;

void print_min_max_pos()
{
    int num, pos, max_num, max_pos, min_num, min_pos;
    ifstream file_stream("task26.txt");

    if (!file_stream.is_open())
    {
        cout << "Failed to open the file";
        return;
    }


    file_stream >> num;
    min_num = num;
    max_num = num;

    pos = 1;
    min_pos = pos;
    max_pos = pos;

    while (file_stream >> num)
    {
        pos++;

        if (num > max_num)
        {
            max_num = num;
            max_pos = pos;
        }
        else if (num < min_num)
        {
            min_num = num;
            min_pos = pos;
        }
    }

    file_stream.close();

    cout << "Min num (" << min_num << ") is at position " << min_pos << endl;
    cout << "Max num (" << max_num << ") is at position " << max_pos << endl;
}

int main()
{
    print_min_max_pos();
    return 0;
}