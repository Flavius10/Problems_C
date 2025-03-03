#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    char a[101];
    cin.getline(a, 101);
    int ind = 0;
    char m[101][101];
    char* p = strtok(a, " ");
    bool ok = false;


    while (p) {
        strcpy(m[++ind], p);
        p = strtok(NULL, " ");
    }

    for (int i = 1; i <= ind; ++i) {
        if (strlen(m[i]) % 2 == 1 && strlen(m[i]) != 1) {
            ok = true;
            int x = strlen(m[i]) - 1;
            for (int j = x / 2; m[i][j]; ++j) {
                m[i][j] = m[i][j + 1];
            }
        }
    }
    if (ok)
        for (int i = 1; i <= ind; ++i)
            cout << m[i] << " ";
    else
        cout << "nu exista";

    return 0;
}