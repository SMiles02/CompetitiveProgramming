#include <bits/stdc++.h>
using namespace std;

vector<int> edges[101];

void dfs(int c, int p, int x)
{
    if (x==0)
        cout<<c<<" ";
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c,x^1);
    if (x)
        cout<<c<<" ";
}

void solve()
{
    int n,x,y;
    cin>>n;
    for (int i=1;i<=n;++i)
        edges[i].clear();
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1,0,0);
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}