#include<fstream>
#include<vector>
#include<set>
using namespace std;

ifstream fin("detdrum2.in");
ofstream fout("detdrum2.out");

using VI = vector<int>;
using VVI = vector<VI>;
using SI = set<int>;

const int Dim = 101;
VI t;
VVI G;
SI st;

bool v[Dim];
int n, p, q;
int rad;
int rad1 = -1;
bool ok = false;

void CitesteDate();
void ParcurgeStanga(int nod);
void ParcurgeDreapta(int nod);
void Dfs(int nod, int cnt);

int main()
{
	CitesteDate();
	ParcurgeStanga(p);
	ParcurgeDreapta(q);
	fout << p << ' ';
	Dfs(p, 1);
	fout << rad1 << ' ';
	Dfs(q, 2);
	fout << q;

	return 0;
}

void CitesteDate()
{
	fin >> n >> p >> q;

	t = VI(n + 1);
	G = VVI(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		fin >> t[i];

		G[t[i]].emplace_back(i);

		if (t[i] == 0)
			rad = i;	
	}
}

void ParcurgeStanga(int nod)
{
	if (nod == 0)
		return;

	v[nod] = true;

	for (int i = 1; i <= n; ++i)
		if (t[nod] == i)
		{
			ParcurgeStanga(i);
		}
}

void ParcurgeDreapta(int nod)
{
	if (nod == 0)
		return;

	if (v[nod] == true && ok == false) {
		rad1 = nod;
		ok = true;
	}

	for (int i = 1; i <= n; ++i)
		if (t[nod] == i)
		{
			ParcurgeDreapta(i);
		}
}

void Dfs(int nod, int cnt)
{
	if (nod == 0)
		return;

	for (int i = 1; i <= n; ++i)
	{
		if (cnt == 1)
		{
			if (t[nod] == i && i != rad1)
			{
				fout << i << ' ';
				Dfs(i, cnt);
			}
		}
		else if (cnt == 2)
		{
			if (t[nod] == i && i != rad1)
			{
				Dfs(i, cnt);
				fout << i << ' ';
			}
		}
	}

}


