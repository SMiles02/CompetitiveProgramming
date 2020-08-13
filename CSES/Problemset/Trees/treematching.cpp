#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,u,v;
set<int> s;
vector<int> edges[200001];

void dfs(int c, int p, int h)
{
    if (s.find(p)==s.end())
    {
        cout<<c<<"!\n";
        s.insert(p);
        s.insert(c);
    }
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c,h+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    s.insert(0);
    dfs(1,0,1);
    cout<<(sz(s)>>1);
    return 0;
}