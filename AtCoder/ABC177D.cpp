#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN=2e5+8;
int cur;
vector<int> edges[MAXN];
bool done[MAXN];

void dfs(int c)
{
    done[c]=1;
    ++cur;
    for (int i : edges[c])
        if (!done[i])
            dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,v,ans=1;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            cur=0;
            dfs(i);
            ans=max(ans,cur);
        }
    cout<<ans;
    return 0;
}