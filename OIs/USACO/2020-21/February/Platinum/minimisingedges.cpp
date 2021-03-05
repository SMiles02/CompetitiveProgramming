#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+1;
int col[N];
bool ok;
vector<int> edges[N];

void dfs(int c)
{
    for (int i : edges[c])
    {
        if (!col[i])
        {
            col[i]=3-col[c];
            dfs(i);
        }
        if (col[i]+col[c]!=3)
            ok=0;
    }
}

void solve()
{
    int n,m,x,y;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        col[i]=0;
        edges[i].clear();
    }
    for (int i=0;i<m;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    col[1]=1;
    ok=1;
    dfs(1);
    if (ok)
        cout<<n-1<<"\n";
    else
        cout<<m<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}