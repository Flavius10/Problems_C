#include<fstream>
using namespace std;

ifstream fin("lantmaxim.in");
ofstream fout("lantmaxim.out");

const int Dim = 1001;
bool a[Dim][Dim];
bool v[Dim];
int n, m;
int p, q;

int L[Dim];
int Lmax[Dim];
int kmax;
int best[Dim];

void CitesteGraf();
void Lant(int x, int k);
void ScrieLant();
void Update(int k);

int main()
{
	CitesteGraf();
	Lant(p, 1);
	ScrieLant();
	return 0;
}

void CitesteGraf()
{
	fin >> n >> m;
	int x, y;

	for (int i = 1; i <= m; ++i)
	{
		fin >> x >> y;
		a[x][y] = a[y][x] = true;
	}
	fin >> p >> q;
}

void Lant(int x, int k)
{
	v[x] = true;
	L[k] = x;

	if (x == q)
	{
		Update(k);
		v[x] = false;
		return;
	}

	for (int y = 1; y <= n; ++y)
		if (!v[y] && a[x][y])
			Lant(x, k + 1);

	v[x] = false;
}

void ScrieLant()
{
	for (int i = 1; i <= kmax; ++i)
		fout << best[i] << ' ';
	fout << '\n';
}

void Update(int k)
{
	if (k > kmax)
	{
		kmax = k;
		for (int i = 1; i <= k; ++i)
			best[i] = L[i];
	}
	fin >> p >> q;
}


