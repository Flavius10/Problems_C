#include<fstream>
using namespace std;

ifstream fin("mere.in");
ofstream fout("mere.out");

const int Dim = 1005;
int n, sum;
int v[Dim];
bool a[Dim][Dim];

void CitesteDate();
void Dfs(int x, int tata);

int main()
{
	CitesteDate();
	Dfs(1, -1);

	fout << sum;
	return 0;
}

void Dfs(int x, int tata)// 1   1
{
	sum += v[x];//3
	int poz = 0;//1

	for (int y = 1; y <= n; ++y)
		if (y != tata && a[x][y] && v[poz] < v[y])
			poz = y;

	if (poz)
		Dfs(poz, x);
}

void CitesteDate()
{
	fin >> n;
	for (int i = 1; i <= n; ++i)
		fin >> v[i];
	for (int i = 0, x, y; i < n; ++i) {
		fin >> x >> y;
		a[x][y] = a[y][x] = true;
	}	
}