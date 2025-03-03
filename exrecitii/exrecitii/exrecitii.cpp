#include<iostream>
using namespace std;

void prefix(int n, int k, int& x)
{
	int cn = n;
	int cnt = 0;
	while (cn)
	{
		cnt++;
		cn /= 10;
	}

	int p = cnt - k;
	while (p)
	{
		p--;
		n /= 10;
	}
	x = n;
}

int main()
{
	int n, k, x;
	cin >> n >> k;
	prefix(n, k, x);
	cout << x;
	return 0;
}