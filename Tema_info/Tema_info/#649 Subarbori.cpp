#include<fstream>
using namespace std;

ifstream fin("subarbori.in");
ofstream fout("subarbori.out");

int n, k, t[101], v[101], cnt, f[101];

int main()
{
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> t[i];

    for (int i = 1; i <= n; i++)
    {
        int p = t[i];
        while (p)
        {
            f[p]++;
            p = t[p];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (f[i] == f[j] && f[i] != 0) cnt++;
    fout << cnt;
}