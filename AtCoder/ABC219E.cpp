//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 4;
vector<int> dx = {0,0,-1,1};
vector<int> dx = {-1,1,0,0};
int s,ct,a[N][N];
bitset<N> on[N], d[N];

bool ok(int x, int y)
{
    return (0<=x&&0<=y&&x<4&&y<4);
}

struct DSU
{
    vector<int> pt,rk;
    DSU(int n) : pt(n+1), rk(n+1, 1)
    {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }

    int find(int i)
    {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }

    void unite(int i, int j)
    {
        i = find(i);
        j = find(j);
        if (i^j)
        {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
};

void dfs(int x, int y)
{
    ++s;
    d[x][y]=1;
    for (int i=0;i<N;++i)
        if (ok(x+dx[i],y+dy[i]))
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j)
            cin>>a[i][j];
    for (int i=0;i<(1<<16);++i)
    {
        for (int j=0;j<16;++j)
        {
            if ((1<<j)&i)
                on[j/4][j%4]=1;
            else
                on[j/4][j%4]=0;
        }
        ct=0;
        for (int i=0;i<N;++i)
            for (int j=0;j<N;++j)
                d[i][j]=0;
        for (int i=0;i<N;++i)
            for (int j=0;j<N;++j)
                if (!d[i][j])
                {
                    s=0;
                    dfs(i,j);
                    ct+=(s>1);
                }
    }
    return 0;
}