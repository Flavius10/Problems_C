#include<iostream>
using namespace std;

int NrDiv(int x)
{
	if (x == 1)  return 0;
	int divizori;

	if (x % 2 == 0)  divizori = 1;
	else  divizori = 0;

	int d;
	for (d = 2; d * d < x; ++d)
	{
		if (x % d == 0)
		{
			if (d % 2 == 0)
				divizori++;
			if (x / d % 2 == 0)
				divizori++;
		}
	}

	if (d * d == x && d % 2 == 0)
		divizori++;


	return divizori;

}

int main()
{
	int a, b;
	int nr_div_pari;
	int NRD = 1;
	int MIN = 10000000, MAX = -1;
	cin >> a >> b;

	for (; a <= b; ++a)
	{
		nr_div_pari = NrDiv(a);
		if (nr_div_pari > NRD)
		{
			NRD = nr_div_pari;
			MIN = MAX = a;
		}
		else if (nr_div_pari == NRD)
		{
			MAX = a;
		}
	}

	cout << NRD << ' ' << MIN << ' ' << MAX;

	return 0;
}
