	#include<iostream>
	using namespace std;

	int Oglindit(int n)
	{
		int ogl = 0;

		while (n)
		{
			ogl = n % 10 + ogl * 10;
			n /= 10;
		}
		return ogl;
	}

	int Cmmdc(int a, int b)
	{
		if (b == 0) return a;
		return Cmmdc(b, a % b);
	}

	int main()
	{
		int n;
		cin >> n;
		int cnt = 0;

		int x;
		for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			int ogl = Oglindit(x);
			if (Cmmdc(ogl, x) == 1)
				cnt++;
		}

		cout << cnt;
		return 0;
	}