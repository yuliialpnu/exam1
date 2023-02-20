#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    double A[1000];
    double B[1000];
    int i = 0, j = 0, k = 0, n = 0;
    double chuslo;
    ifstream a("f.txt");
    ifstream b("g.txt");
    if (!a.is_open())
    {
        cout << "Can't open f.txt " << endl;
        return 1;
    }
    if (!b.is_open())
    {
        cout << "Can't open g.txt " << endl;
        return 1;
    }
    while (a >> chuslo)
    {
        A[i] = chuslo;
        i++;
        n++;
    }
    while (b >> chuslo)
    {
        B[j] = chuslo;
        j++;
        k++;
    }
    a.close();
    b.close();
    double F[1000];
    int s = 0, p = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < k; j++)
        {
            if ((A[i] == B[j]))
            {
                F[p] = A[i];
                p++;
                s++;
            }
        }
    }
    for (p = 0; p < s; p++)
    {
        cout << F[p] << endl;
    }
    ofstream c("ff.txt");
    if (!c.is_open())
    {
        cout << "Can't open ff.txt " << endl;
        return 1;
    }
    for (p = 0; p < s; p++)
    {
        c << F[p] << endl;
    }
    cout << "WELL DONE" << endl;
    c.close();
    return 0;
}