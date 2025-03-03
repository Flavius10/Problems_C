#include<iostream>
using namespace std;

const int Dim = 25;
int a[Dim][Dim];

int main()
{
	int n, k;
	cin >> n >> k;
	int p = 2;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i <= k && j <= k)
				a[i][j] = 1;
			else if (i <= k && j > k)
				a[i][j] = 2;
			else if (i > k && j <= k)
				a[i][j] = 3;
			else
				a[i][j] = 4;
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}