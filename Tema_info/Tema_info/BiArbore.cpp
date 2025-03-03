#include <iostream>
#include <fstream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fin("bilatime.in");
ofstream fout("bilatime.out");


struct Nod {
    int val;
    Nod* fs, * fd;
};

int val;
Nod* CitPreOrd()
{
    fin >> val;
    if (val == 0) return nullptr;
    Nod* ptr = new Nod;

    ptr->val = val;
    ptr->fs = CitPreOrd();
    ptr->fd = CitPreOrd();
    return ptr;
}

void DezalocArb(Nod* ptr)
{
    if (ptr == nullptr) return;
    DezalocArb(ptr->fs);
    DezalocArb(ptr->fd);
    delete ptr;
}

set<int> frunze;

void Bfs(Nod* ptr)
{
    queue<Nod*> Q;
    Q.push(ptr);
    fout << ptr->val << ' ';
    while (!Q.empty())
    {
        ptr = Q.front();
        Q.pop();
        if (ptr->fs)
        {
            Q.push(ptr->fs);
            fout << ptr->fs->val << ' ';
        }

        if (ptr->fd)
        {
            Q.push(ptr->fd);
            fout << ptr->fd->val << ' ';
        }
    }
}

int main()
{
    Nod* root = CitPreOrd();
    Bfs(root);
    DezalocArb(root);

    return 0;
}
