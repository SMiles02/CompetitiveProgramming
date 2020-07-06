#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll maxAns;
map<int,vector<pair<int,int>>> children;
vector<int> s;

void dfs(int cur, int deltaLeft, ll curAns)
{
    curAns+=s[cur];
    maxAns=max(curAns,maxAns);
    int k=sz(children[cur]);
    for (int i=0;i<k;++i)
    {
        if (children[cur][i].second<=deltaLeft)
        {
            dfs(children[cur][i].first, deltaLeft-children[cur][i].second,curAns);
        }
    }
}

void solve()
{
    maxAns=0;
    children.clear();
    s.clear();
    int n,m,V,k,a,b;
    cin>>n>>m>>V;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        s.push_back(k);
    }
    for (int i=0;i<m;++i)
    {
        cin>>a>>b>>k;
        children[a].push_back({b,k});
    }
    dfs(0,V,0);
    cout<<maxAns;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}