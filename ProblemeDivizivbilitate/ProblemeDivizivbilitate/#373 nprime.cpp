#include<iostream>
using namespace std;

int nrdiv(int x)
{
    int d = 2, p = 0;
    int cnt = 0;
    while (x != 1)
    {
        p = 0;
        while (x % d == 0)
        {
            p++;
            x /= d;
        }
        if (p > 0)
            cnt++;

        if (d == 2)
            d = 3;
        else
            d += 2;

        if (d * d > x)
            d = x;
    }
    return cnt;
}

int main()
{
    int a, b;
    cin >> a;
    int max = nrdiv(a), nmax = a;
    while (1)
    {
        cin >> b;
        if (a == b)
            break;
        if (nrdiv(b) > max)
            max = nrdiv(b), nmax = b;
        else
            if (nrdiv(b) == max)
                if (b > nmax)
                    nmax = b;
        a = b;
    }
    cout << nmax << ' ' << max;
    return 0;
}