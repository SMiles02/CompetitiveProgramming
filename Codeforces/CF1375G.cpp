#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> edges[200001];
int a[2];

void dfs(int c, int p, int x)
{
    ++a[x];
    for (int i : edges[c])
        if (i != p)
            dfs(i,c,x^1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,u,v;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0,0);
    cout<<min(a[0],a[1])-1;
    return 0;
}