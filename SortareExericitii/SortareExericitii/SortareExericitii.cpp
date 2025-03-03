#include<iostream>
using namespace std;

int main()
{
	int x, y;

	cin >> x >> y;

	cout << y << ' ' << x << ' ';
	int n = (y - x) / 2 - 1;

	while (n)
	{
		y = x; //21
		x = y - 2 * (n + 1); // 
		cout << y << ' ' << x << ' ';
		--n;
	}

	return 0;
}