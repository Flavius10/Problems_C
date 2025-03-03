#include <fstream>
using namespace std;

ifstream fin("componenteconexe2.in");
ofstream fout("componenteconexe2.out");

const int Dim = 105;
int n, a[Dim][Dim];
int x[Dim], v[Dim]; 
int nrv[Dim],  nrm[Dim]; 

void bf(int varf, int nrc)
{
    int st, dr;
    st = dr = 1;
    v[varf] = nrc;
    x[1] = varf;
    while (st <= dr)
    {
        int k = x[st];
        for (int i = 1; i <= n; ++i)
            if (v[i] == 0 && a[k][i] == 1)
            {
                dr++;
                v[i] = nrc;
                x[dr] = i;
            }
        st++;
    }
}

int main()
{
    int i, j;
    fin >> n;
    while (fin >> i >> j)
    {
        a[i][j] = a[j][i] = 1;
    }

    int nrc = 0;
    for (int i = 1; i <= n; ++i)
        if (v[i] == 0)
        {
            nrc++;
            bf(i, nrc);
        }

    for (int i = 1; i <= n; i++)
        nrv[v[i]] ++;

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; ++j)
            if (a[i][j] == 1)
                nrm[v[i]] ++;

    int C = 0;
    for (int i = 1; i <= nrc; ++i)
        C += nrm[i] - nrv[i] + 1;
    fout << C;
    return 0;
}