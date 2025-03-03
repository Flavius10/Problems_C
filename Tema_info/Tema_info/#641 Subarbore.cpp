#include<fstream>
#include<set>
using namespace std;

ifstream fin("subarborenumarare.in");
ofstream fout("subarborenumarare.out");

const int Dim = 101;
int n, k;
int t[Dim];
int rad, rad1;
int nr[Dim], nr1[Dim];

using SI = set<int>;

SI st;

void CitesteDate();
void Dfs(int nod);

int main()
{
	CitesteDate();
	Dfs(k);
	
	size_t st_size = st.size();

	fout << st_size;
	return 0;
}

void CitesteDate()
{
	fin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		fin >> t[i];

		if (t[i] == 0)
			rad = i;
	}

	st.insert(k);
}

void Dfs(int nod)
{

	for (int i = 1; i <= n; ++i)
	{
		if (t[i] == nod)
		{
			st.insert(i);
			Dfs(i);
		}
	}
}

