#include<iostream>
#include<iomanip>
using namespace std;

int n = 100;///variabila globala
const int Dim = 100;

int main()
{
    int m = 10;///variabila locala

    char caracter = 'a';
    char car = toupper(caracter);

    float numar = 138.24838567;
    ///cout << fixed << setprecision(8) << numar;
    ///cout << car;

    string name = "Flavius";
    ///cout << name[0] << ' ';

    bool ok = true;
/*
    int a[5] = {10, 20 , 30 ,40 , 50};

    int i = 0;

    while(ok)
    {
        if(a[i] == 40)
            ok = false;

        cout << a[i] << ' ';
        i++;
    }

    cout << i << ' ';
*/

    int a = 50;
    int b = 35;

    //cout << a + b << ' ' << a - b << ' ' << a * b << ' ' << b / a << ' ' << b % a;

    if(a < b)
        cout << a << ' ';
    if(a > b)
        cout << b << ' ';
    if(a >= b)
        cout << a << ' ';
    if(a <= b)
        cout << b << ' ';
    if(a == b)
        cout << a << ' ';
    if(a != b)
        cout << b << ' ';

    return 0;
}
