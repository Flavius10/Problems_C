#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include<cstring>
using namespace std;

ifstream fin("palindrom.in");
ofstream fout("palindrom.out");

bool Palindrom(char sir[])
{
	for (int i = 0; i < strlen(sir) / 2; ++i)
		if (sir[i] != sir[strlen(sir) - i - 1])
			return false;
	return true;
}

int main()
{
	int n;
	fin >> n;

	fin.get();
	char x[21];

	for (int i = 1; i <= n; ++i)
	{
		fin >> x;
		if (Palindrom(x))
			fout << 1 << '\n';
		else
			fout << 0 << '\n';
	}

}

