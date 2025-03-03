#include<fstream>
#include<vector>
#include<set>
using namespace std;

ifstream fin("detdrum.in");
ofstream fout("detdrum.out");

int t[101], n, k;

int main()
{
    fin >> n >> k;
    for (int i = 1; i <= n; i++)
        fin >> t[i];
    while (k)
    {
        fout << k << " ";
        k = t[k];
    }
}