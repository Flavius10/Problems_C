#include<iostream>
using namespace std;

int Cmmdc(int a, int b)
{
	if (b == 0) return a;
	return Cmmdc(b, a % b);
}

int main()
{
	int n;
	cin >> n;
	
	int div = 0;
	int x, y;
	cin >> x >> y;
	div = Cmmdc(x, y);
	for (int i = 1; i <= n - 2; ++i)
	{
		cin >> x;
		div = Cmmdc(x, div);
	}
	cout << div;
	return 0;
}