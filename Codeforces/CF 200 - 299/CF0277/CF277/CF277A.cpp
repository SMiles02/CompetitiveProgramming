#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,int> donePeople;
map<int,vector<int>> edges;

void dfs(int n)
{
    int k=sz(edges[n]);
    for (int i=0;i<k;++i)
    {
        if (!donePeople[edges[n][i]])
        {
            donePeople[edges[n][i]]=1;
            dfs(edges[n][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,p,ans=0,checker=0;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        if (!k)
        {
            ++checker;
        }
        for (int j=0;j<k;++j)
        {
            cin>>p;
            edges[i].push_back(m+p);
            edges[m+p].push_back(i);
        }
    }
    for (int i=1;i<=n;++i)
    {
        if (!donePeople[i])
        {
            donePeople[i]=1;
            dfs(i);
            ++ans;
        }
    }
    cout<<max(ans-1,checker);
    return 0;
}