#include<iostream>
using namespace std;

const int Dim = 10001;
int a[Dim];
int Mod = 1;
int b;

int Putere1(int p)
{
	if (p == 0)
		return 1;

	int x = Putere1(p / 2); // 1
	x = (1ULL * x * x) % Mod;
	if (p % 2)	
	{
		x = (1ULL * x * b) % Mod;
	}
	return x;
}

int main()
{
	int n, p;
	cin >> b >> n >> p;
	for (int i = 1; i <= p; ++i)
		Mod *= 10;
	cout << Putere1(n);

	return 0;
}