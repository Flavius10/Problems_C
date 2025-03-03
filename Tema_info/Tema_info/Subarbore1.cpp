#include<fstream>
#include<vector>
using namespace std;

ifstream fin("nivelebin.in");
ofstream fout("nivelebin.out");

struct Nod {
	int x;
	int st, dr;
};

using VI = vector<int>;
using VN = vector<Nod>;

VI t;
VN arb;
int n, rad;
VI nivel;
int maxi = -1;

void CitesteDate();
void Dfs(int nod, int niv);

int main()
{
	CitesteDate();
	Dfs(rad, 0);

	fout << maxi << '\n';

	for (int i = 0; i < maxi; ++i)
	{
		fout << nivel[i] << ' ';
	}

	return 0;
}

void CitesteDate()
{
	fin >> n;

	int x, st, dr;

	t = VI(n + 1);
	arb = VN(n + 1);
	nivel = VI(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		fin >> x >> dr >> st;
		arb[i] = { x, st, dr };

		if (st) t[st] = i;
		if (dr) t[dr] = i;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (t[i] == 0)
		{
			rad = i;
			break;
		}
	}
}

void Dfs(int nod, int niv)
{
	if (nod == 0)
		return;

	maxi = max(maxi, niv + 1);

	nivel[niv]++;

	Dfs(arb[nod].st, niv + 1);
	Dfs(arb[nod].dr, niv + 1);
}
