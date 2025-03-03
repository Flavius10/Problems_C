#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

const int Dim = 101;
char a[Dim][Dim];
char c[Dim];
char t[Dim];
char f[Dim];
int ind = 0;

int main()
{
	cin.getline(c, 101);
	char* p = strtok(c, " ");

	bool ok = false;

	while (p)
	{
		strcpy(a[++ind], p);
		p = strtok(nullptr, " ");
	}
	
	for (int i = 1; i <= ind; ++i)
	{
		if (strlen(a[i]) >= 3 && strlen(a[i]) % 2 == 1)
		{
			strcpy(t, a[i] + strlen(a[i]) / 2 + 1);
			strcpy(a[i] + strlen(a[i]) / 2, t);
			ok = true;
		}

		strcat(f, a[i]);
		strcat(f, " ");
	}

	if (ok)
		cout << f << ' ';
	else
		cout << "nu exista";
	return 0;
}