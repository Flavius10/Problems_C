#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

char v[31];
int nr = 0;

int main()
{
	char a[31];
	char b[31];

	cin >> a >> b;

	for (int i = 0; i < strlen(a); ++i)
	{
		if (strchr("aeiou", a[i]) && strchr("aeiou", b[i]))
			v[nr++] = '*';
		else if (!strchr("aeiou", a[i]) && !strchr("aeiou", b[i]))
			v[nr++] = '#';
		else if (strchr("aeiou", a[i]) && !strchr("aeiou", b[i]))
			v[nr++] = '?';
		else if (!strchr("aeiou", a[i]) && strchr("aeiou", b[i]))
			v[nr++] = '?';
	}

	cout << v;

	return 0;
}