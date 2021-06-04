#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+7;
int g[N], tin[N], low[N], sub[N], t, ct, cur, same[N];
long long ans;
vector<int> e[N], bccE[N*4];
set<int> s[N];
bitset<N> d1, d2, ap;

void dfs1(int c, int p)
{
    int cd=0;
    d1[c]=1;
    ++ct;
    tin[c] = low[c] = ++t;
    vector<int> v;
    for (int i : e[c])
        if (i!=p)
        {
            if (d1[i])
                low[c]=min(low[c],tin[i]);
            else
            {
                dfs1(i,c);
                low[c]=min(low[c],low[i]);
                if (p==0)
                    v.push_back(i);
                else if (tin[c]<=low[i])
                {
                    ap[c]=1;
                    s[c].insert(i);
                }
                ++cd;
            }
        }
    if (p==0&&cd>1)
    {
        ap[c]=1;
        for (int i : v)
            s[c].insert(i);
    }
}

void dfs2(int c, int gp)
{
    d2[c]=1;
    bccE[c].push_back(gp);
    bccE[gp].push_back(c);
    for (int i : e[c])
        if (!d2[i])
        {
            if (s[c].count(i))
            {
                ++cur;
                bccE[c].push_back(cur);
                dfs2(i,cur);
            }
            else
                dfs2(i,gp);
        }
}

void bccDfs(int c, int p)
{
    cout<<c<<"\n";
    for (int i : bccE[c])
        if (i!=p)
            bccDfs(i,c);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    cur=n;
    while (m--)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        if (!d1[i])
        {
            ct=0;
            dfs1(i,0);
            dfs2(i,++cur);
            bccDfs(i,0);
        }
    cout<<ans;
    return 0;
}