#include<fstream>
using namespace std;

ifstream fin("detdrum1.in");
ofstream fout("detdrum1.out");

const int Dim = 101;
int n, k, p;
int rad;
int t[Dim];
int sir[Dim];
int nr = 0;
int cnt = 0;

void Drum(int k, int p);

int main()
{
	fin >> n >> k >> p;

	for (int i = 1; i <= n; ++i)
	{
		fin >> t[i];
	}

	Drum(k, p);

	return 0;
}


void Drum(int k,int p)//0
{
	if (k != p)
	{
		Drum(t[k], p);
		fout << k << ' ';
	}
}