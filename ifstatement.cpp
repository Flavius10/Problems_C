#include<iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int s1 = m % 10 + m / 10;
    int s2 = n % 10 + n / 10;

    int p1 = (m % 10) * ( m / 10) * (n % 10) * (n / 10);

    if(n % 2 == m % 2)
        cout << s1 + s2;
    else
        cout << p1;


    return 0;
}
