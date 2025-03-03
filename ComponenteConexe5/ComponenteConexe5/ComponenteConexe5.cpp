#include<fstream>
using namespace std;

ifstream fin("bazine.in");
ofstream fout("bazine.out");

const int N = 101;
int a[N][N];
int v[N];
int n, m, nrc;

void CitesteGraf();
void Dfs(int x, int val);

int main()
{
    CitesteGraf();

    for (int i = 1; i <= n; ++i)
        if (v[i] == 0)
        {
            Dfs(i, nrc + 1);
            nrc++;
        }

    fout << nrc << '\n';

    return 0;
}

void CitesteGraf()
{
    fin >> n >> m;
    int x, y;

    while (fin >> x >> y)
    {
        a[x][y] = a[y][x] = 1;
    }

}

void Dfs(int x, int val)
{
    v[x] = val;

    for (int y = 1; y <= n; ++y)
        if (a[x][y] == 1 && !v[y])
        {
            Dfs(y, val);
            v[y] = val;
        }

}