#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+1, mod = 1e9+7;
int ht[N],mx;
vector<int> edges[N];

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

void dfs(int c, int p, int h)
{
    mx=max(mx,h);
    ++ht[h];
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c,h+1);
}

void solve()
{
    int n,m,x,y;
    cin>>n>>m;
    mx=0;
    for (int i=0;i<=n;++i)
    {
        ht[i]=0;
        edges[i].clear();
    }
    for (int i=0;i<m;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1,0,0);
    ll ans=1;
    for (int i=1;i<=mx;++i)
        ans=(ans*binpow((binpow(2,ht[i-1])+mod-1)%mod,ht[i]))%mod;
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}