#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn = 1e5+7;
int x,y,z;
vector<int> edges[maxn];

void dfs(int c, int p, int h, int k)
{
    if (c==k)
        z=h;
    if (h>x)
    {
        x=h;
        y=c;
    }
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c,h+1,k);
}

void solve()
{
    int n,a,b,dA,dB,u,v;
    cin>>n>>a>>b>>dA>>dB;
    for (int i=1;i<=n;++i)
        edges[i].clear();
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    x=0;
    dfs(1,0,0,0);
    dfs(y,0,0,0);
    dA=min(dA,x);
    dB=min(dB,x);
    dfs(a,0,0,b);
    //cout<<dA<<" "<<dB<<"\n";
    if (dB<=dA*2||z<=dA)
        cout<<"Alice\n";
    else
        cout<<"Bob\n";
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