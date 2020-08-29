#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1e9+7;
vector<int> edges[100001];
bool winning[100001];

void winningDFS(int c, int p)
{
    winning[c]=0;
    for (int i : edges[c])
        if (i!=p)
        {
            winningDFS(i,c);
            if (!winning[i])
                winning[c]=1;
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,u,v;
    ll d,ans=0;
    cin>>n>>d;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        edges[u+1000].push_back(v+1000);
        edges[v+1000].push_back(u+1000);
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            edges[i].push_back(j+1000);
            winningDFS(1,0);
            if (winning[1])
                ++ans;
            edges[i].pop_back();
        }
    cout<<ans%mod;
    return 0;
}