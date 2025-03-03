#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("bac.txt");

int main()
{
	int nr;
	int index = 0;
	int p = -1, pm = 0;

	while (fin >> nr)
	{
		index++;
		if (nr > p)
		{
			p = nr;
			pm = index;
			cout << nr << ' ';
		}

		if (nr == p && index == pm + 1)
		{
			cout << nr << ' ';
			pm = index;
		}
	}

	return 0;
}