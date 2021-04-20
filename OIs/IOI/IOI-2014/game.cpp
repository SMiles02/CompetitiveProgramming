#include <bits/stdc++.h>
using namespace std;

const int N = 1500;
int n, pt[N], sz[N], e[N][N];

int find(int x)
{
    if (x==pt[x])
        return x;
    return pt[x] = find(pt[x]);
}

void unite(int x, int y)
{
    if (sz[y]>sz[x])
        swap(x,y);
    pt[y]=x;
    sz[x]+=sz[y];
    for (int i=0;i<n;++i)
    {
        e[x][i]+=e[y][i];
        e[i][x]=e[x][i];
    }
}

int hasEdge(int u, int v)
{
    int x = find(u), y = find(v);
    if (x == y)
        return 0;
    if (e[x][y]==1)
    {
        unite(x,y);
        return 1;
    }
    --e[x][y];
    --e[y][x];
    return 0;
}

void initialize(int k)
{
    n=k;
    for (int i=0;i<n;++i)
    {
        pt[i]=i;
        sz[i]=1;
    }
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            e[i][j]=1;
}