#include<fstream>
#include<vector>
using namespace std;

ifstream fin("nrfii.in");
ofstream fout("nrfii.out");

const int Dim = 101;
int n, rad;
int val_max = 0;
int t[Dim];

vector<int> frecventa;

void CitesteDate();

int main()
{
	CitesteDate();
}

void CitesteDate()
{
	fin >> n;

	frecventa = vector<int>(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		fin >> t[i];
		frecventa[t[i]]++;

		if (t[i] == 0)
			rad = i;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (frecventa[t[i]] > val_max)
		{
			val_max = frecventa[t[i]];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (frecventa[i] == val_max)
			fout << i << ' ';
	}

}