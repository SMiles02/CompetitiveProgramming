#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+7;
int n, m, fishy[N], surang[N];
ll score[N];
bitset<N> d, col;
bool ok;
vector<int> e[N], f[N];

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

ll dfs(int c, int p)
{
    for (int i : e[c])
        if (i!=p)
            score[c]+=dfs(i,c);
    return -score[c];
}

void dfs(int c)
{
    d[c]=1;
    for (int i : f[c])
    {
        if (!d[i])
        {
            col[i]=col[c]^1;
            dfs(i);
        }
        else if (col[i]==col[c])
            ok=0;
    }
}

void solve()
{
    cin>>n>>m;
    int x,y,z=0;
    DSU dsu(n);
    for (int i=1;i<=n;++i)
    {
        e[i].clear();
        f[i].clear();
        d[i]=0;
    }
    for (int i=1;i<=n;++i)
        cin>>fishy[i];
    for (int i=1;i<=n;++i)
        cin>>surang[i];
    for (int i=1;i<=n;++i)
    {
        score[i]=surang[i]-fishy[i];
        z+=score[i]&1;
    }
    while (m--)
    {
        cin>>x>>y;
        if (dsu.find(x)!=dsu.find(y))
        {
            dsu.unite(x,y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        f[x].push_back(y);
        f[y].push_back(x);
    }
    ok=1;
    dfs(1);
    if (z&1)
        cout<<"NO\n";
    else if (!ok)
        cout<<"YES\n";
    else if (dfs(1,0)!=0)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}