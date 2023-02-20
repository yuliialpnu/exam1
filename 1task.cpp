//1. Для заданої функції y=f(x) на інтервалі [c, d] , рухаючись з кроком h=(d-c)/n , знайти сегменти, де функція змінює знак.

#include<iostream>
#include<iomanip>
#include<cmath> 
using namespace std;
const int max_size = 100;

int main() {
    double c, tmp, d, h, x, y, x_start, x_1[20], x_end;
    int n, pr, prc, i = 0, m;
    cout << " \n Enter left limit c = ";
    cin >> c;
    cout << "Enter (end point) d= "; cin >> d;
    if (c > d) {
        tmp = c; c = d; d = tmp;
    }
    do {
        cout << "Enter (numder of points) (n>0) n= \n";
        cin >> n;
    } while (n <= 0);
    h = (d - c) / n;
    x = c;
    y = sin(x);
    cout << "\n y=" << y << "\t for x=" << x;
    if (y > 0) pr = 1;
    else if (y < 0) pr = 0;
    else {
        for (x = c + h; y == 0; x += h) {
            y = sin(x);
            if (y > 0) pr = 1;
            else if (y < 0) pr = 0;
        }
    }

    for (x = c + h; x < d; x += h)
    {
        y = sin(x);
        cout << "\n y=" << y << "\t for x=" << x;
        if (y > 0) prc = 1;
        else if (y < 0) prc = 0;
        if (prc != pr) {
            x_1[i] = x - h;
            i++;
            x_1[i] = x;
            i++;
            break;
        }
    }
    while (x <= d) {
        pr = prc;
        for (x = x + h; x < d; x += h) {
            y = sin(x);
            cout << "\n y=" << y << "\t for x=" << x;
            if (y > 0) prc = 1;
            else if (y < 0) prc = 0;
            if (prc != pr) {
                x_1[i] = x - h;
                i++;
                x_1[i] = x;
                i++;
                break;
            }
        }
    }
    if (i == 0) cout << "\nThe function does not change the sign";
    else {
        m = i - 1;
        cout << "\nThe function changes the sign at such intervals";
        cout << "\n[" << x_1[0] << ", " << x_1[1] << "]";
        for (i = 2; i < m - 1; i += 2) {
            cout << "\nand [" << x_1[i] << ", " << x_1[i + 1] << "]";
        }
        cout << "\n end of program \n";
        system("pause");
        return 1;
    }

}