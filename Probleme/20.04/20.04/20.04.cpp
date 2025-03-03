#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("frunze.in");
ofstream fout("frunze.out");

const int Dim = 101;
int n, rad;
int tata[N];

int main()
{
	fin >> n; 

	for (int i = 1; i <= n; ++i)
	{
		fin >> tata[i];
		if (tata[i] = 0)
			rad = i;
	}

	fout << rad << '\n';
	int nr_frunze = 0;

	for (int j = 1; j <= n; ++j)
	{
		bool g = false;

		for (int i = 1; i <= n; ++i)
			if (j == tata[i])
				g = true;

		if (!g)
			nr_frunze++;
	}

	fout << nr_frunze << '\n';

	for (int x = 1; x <= n; ++x)
	{
		bool g = false;

		for (int i = 1; i <= n; ++i)
		{
			if (x == tata[i])
				g = true;

			if (!g)
				fout << x << ' ';
		}
	}




	return 0;
}