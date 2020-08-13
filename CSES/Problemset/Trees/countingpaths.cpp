#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN=2e5+1;
ll sub[MAXN];
int parent[MAXN],n,u,v;
vector<int> edges[MAXN];

void dfs(int c, int p)
{
    sub[c]=1;parent[c]=p;
    for (int i : edges[c])
        if (i!=p)
        {
            dfs(i,c);
            sub[c]+=sub[i];
        }
}   

int ans(int x)
{
    ll ans=0;
    int cur=1;
    for (int i : edges[x])
        if (i!=parent[x])
        {
            ans+=sub[i]*cur;
            cur+=sub[i];
        }
    ans+=(sub[parent[x]]-sub[x])*cur;
    return ans;
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
    dfs(1,0);
    for (int i=1;i<=n;++i)
        cout<<ans(i)<<" ";
    return 0;
}