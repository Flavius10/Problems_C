#include<iostream>
using namespace std;

const int Dim = 101;
int a[Dim][Dim];

int main()
{
	int n, m;
	bool ok = true;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m / 2; ++j)
		{
			if (a[i][j] != a[i][m - j + 1])
			{
				ok = false;
				break;
			}
		}
	}


	if (ok)
		cout << "DA";
	else
		cout << "NU";
	return 0;
}