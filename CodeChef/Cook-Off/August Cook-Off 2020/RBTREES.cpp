#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN 1e5+10;
vector<int> edges[MAXN];
int am[2];

void dfs(int c, int p, int h)
{
    
}

void solve()
{
    int n,u,v;
    cin>>n;
    for (int i=1;i<=n;++i)
        edges[i].clear();
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    am[0]=0;am[1]=0;
    dfs(1,0,0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    return 0;
}