#include <fstream>
using namespace std;

ifstream fin("euler.in");
ofstream fout("euler.out");

const int N = 201;
int n, m, x, y;
bool a[N][N], v[N][N];
int c[N], cc;
int gr[N];
int l[40000];

void CitesteGraf();
void DFS(int x);
void Euler(int k);
bool EsteConex();
bool EsteEulerian();
bool Ok(int k);
void ScrieCiclu();

int main()
{
    CitesteGraf();

    if (EsteEulerian())
    {
        l[1] = 1;
        Euler(2);
    }

    return 0;
}

void CitesteGraf()
{
    fin >> n;
    while (fin >> x >> y)
    {
        a[x][y] = a[y][x] = true;
        ++m;
    }
}

void DFS(int x)
{
    c[x] = cc;

    for (int y = 1; y <= n; ++y)
        if (!c[y] && a[x][y])
            DFS(y);
}

void Euler(int k)
{
    if (k == m + 2)
    {
        if (l[m + 1] == 1)
            ScrieCiclu();
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        l[k] = i;

        if (Ok(k))
        {
            v[l[k - 1]][i] = true;
            Euler(k + 1);
            v[l[k - 1]][i] = false;
        }
    }
}

bool EsteConex()
{
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i])
        {
            cc++;
            DFS(i);
        }
    }

    if (cc == 1)
        return true;
    return false;
}

bool EsteEulerian()
{
    for (int i = 1; i <= n; ++i)
        if (gr[i] % 2 == 1)
            return false;

    if (!EsteConex())
        return false;

    return true;;
}

bool Ok(int k)
{
    if (v[l[k - 1]][l[k]] ||
        v[l[k]][l[k - 1]])
        return false;

    if (!a[l[k - 1]][l[k]])
        return false;

    return true;
}

void ScrieCiclu()
{
    fout << m + 1 << '\n';

    for (int i = 1; i <= m + 1; ++i)
        fout << l[i] << ' ';
    fout << '\n';
    exit(0);
}