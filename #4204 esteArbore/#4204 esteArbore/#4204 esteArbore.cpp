#include<fstream>
using namespace std;

ifstream fin("estearbore.in");
ofstream fout("estearbore.out");

const int N = 101;
bool a[N][N];
bool v[N];
int n;
int x, y;
int nrc;
bool ok = true;

void CitesteGraf();
void Dfs(int x, int val);

int main()
{
	CitesteGraf();

	for (int i = 1; i <= n; ++i)
	{
		if (v[i] == false)
		{
			nrc++;
			Dfs(i, nrc);
		}
	}	

	for (int i = 3; i <= n; ++i)
		if (a[1][i] && a[i][i - 1])
			ok = false;

	if (ok && nrc == 1)
		fout << "DA";
	else
		fout << "NU";
		

	return 0;
}


void CitesteGraf()
{
	fin >> n;

	while (fin >> x >> y)
	{
		a[x][y] = a[y][x] = true;
	}
}

void Dfs(int x, int val)
{
	v[x] = val;

	for (int y = 1; y <= n; ++y)
	{
		if (a[x][y] && !v[y])
		{
			Dfs(y, val);
			v[y] = val;
		}
	}
}