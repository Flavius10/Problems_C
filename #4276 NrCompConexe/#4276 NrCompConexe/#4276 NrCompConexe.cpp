#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char a[101][101];
	char s[101];
	int n = 0;
	int nr = 0;

	cin.getline(s, 101);

	char* p = strtok(s, " ");

	while (p != nullptr)
	{
		strcpy(a[++n], p);
		p = strtok(nullptr, " ");
	}

	for (int i = 1; i <= n; ++i)
	{	
		int l = strlen(a[i]);
		char cp[101];
		strcpy(cp, a[i]);

		if (l % 2 == 1)
		{
			for (int j = 0; j < l / 2; ++j)
			{
				char temp = a[i][j];
				a[i][j] = a[i][l - j - 1];
				a[i][l - j - 1] = temp;
			}
			if (cp != a[i])
				nr++;
		}
	}

	if (nr)
		for (int i = 1; i <= n; ++i)
			cout << a[i] << ' ';
	else
		cout << "nu exista";

		
	return 0;
}