#include<fstream>
#include<queue>
using namespace std;

ifstream fin("lant1.in");
ofstream fout("lant1.out");

const int Dim = 105;
bool a[Dim][Dim];
bool v[Dim];
int n, p, q, r;
int Lant[Dim];
int L;
int tata[Dim];
int dublura;

void CitesteDate();
void Reverse(int x);
void Bfs(int x, int fin);
void ScrieDate();
void Clean();

int main()
{
	CitesteDate();

	Bfs(p, r);
	Reverse(r);
	Clean();

	Bfs(r, q);
	dublura = true;
	Reverse(q);

	ScrieDate();
	return 0;
}

void ScrieDate()
{
	fout << L << '\n';

	for (int i = 1; i <= n; ++i)
		fout << Lant[i] << ' ';
}

void CitesteDate()
{
	fin >> n >> p >> q >> r;
	int x, y;

	while (fin >> x >> y)
	{
		if (!a[x][y])
			a[x][y] = a[y][x] = true;
	}
}

void Reverse(int x)
{
	if (x == 0)
		return;

	Reverse(tata[x]);

	if (dublura)
	{
		dublura = false;
		return;
	}

	Lant[++L] = x;
}

void Bfs(int x, int fin)
{
	v[x] = true;
	queue<int> Q;

	Q.push(x);

	while (!Q.empty())
	{
		x = Q.front();
		Q.pop();

		for (int y = 1; y <= n; ++y)
		{
			if (!v[y] && a[x][y])
			{
				v[y] = true;
				Q.push(y);
				tata[y] = x;
			}

			if (tata[fin])
				return;
		}
	}
}


void Clean()
{
	for (int i = 1; i <= n; ++i)
	{
		v[i] = false;
		tata[i] = false;
	}

}