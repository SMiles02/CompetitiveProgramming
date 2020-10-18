#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn=1e5+7;
int n,sub[maxn],mini;
vector<int> edges[maxn], cents;

void dfs(int c, int p)
{
    int cur=0;
    sub[c]=1;
    for (int i : edges[c])
        if (i!=p)
        {
            dfs(i,c);
            sub[c]+=sub[i];
            cur=max(cur,sub[i]);
        }
    cur=max(cur,n-sub[c]);
    if (cur<mini)
    {
        mini=cur;
        cents.clear();
        cents.push_back(c);
    }
    else if (cur==mini)
        cents.push_back(c);
}

void solve()
{
    int u,v;
    cin>>n;
    for (int i=1;i<=n;++i)
        edges[i].clear();
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    mini=maxn;
    cents.clear();
    dfs(1,0);
    if (sz(cents)==1)
        cout<<"1 "<<edges[1][0]<<"\n1 "<<edges[1][0]<<"\n";
    else
    {
        for (int i : edges[cents[0]])
            if (i!=cents[1])
            {
                cout<<cents[0]<<" "<<i<<"\n";
                cout<<cents[1]<<" "<<i<<"\n";
                return;
            }
    }
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