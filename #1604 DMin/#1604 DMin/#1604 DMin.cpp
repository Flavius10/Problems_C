#include<fstream>
#include<vector>
#include<queue>
using namespace std;

ifstream fin("dmin.in");
ofstream fout("dmin.out");

using VI = vector<int>;
using VB = vector<bool>;
using VVI = vector<VI>;

VVI G;
VB v;
VI d;
int n, m;
int k;
int x, y;
int l, r;

void Bfs(int x);

int main()
{
	fin >> n >> m;

	G = VVI(n + 1);
	v = VB(n + 1);
	d = VI(n + 1);

	while (m)
	{
		fin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
		m--;
	}

	fin >> k;

	while (k)
	{
		fin >> l >> r;
		Bfs(l);
		fout << d[r] << '\n';
		k--;
	}

	return 0;
}

void Bfs(int x)
{
	queue<int> Q;

	for (int i = 1; i <= n; ++i)
		d[i] = v[i] = 0;

	v[x] = true;
	d[x] = 0;
	Q.push(x);

	while (!Q.empty())
	{
		x = Q.front();
		Q.pop();

		for (auto const& y : G[x])
		{
			if (v[y])continue;

				v[y] = true;
				d[y] = d[x] + 1;
				Q.push(y);
		}
	}
}