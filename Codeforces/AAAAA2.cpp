#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn=1e5+7,mod=1e9+7;
vector<int> edges[maxn];

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
        return (res * a)%mod;
    return res;
}

ll add(ll a, ll b)
{
    return (a+b)%mod;
}

ll sub(ll a, ll b)
{
    return (((a-b)%mod)+mod)%mod;
}

int ct;
bitset<maxn> done;

void dfs(int c)
{
    done[c]=1;
    ++ct;
    for (int i : edges[c])
        if (!done[i])
            dfs(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,y,z;
    cin>>n>>k;
    ll ans=binpow(n,k);
    for (int i=1;i<n;++i)
    {
        cin>>x>>y>>z;
        if (!z)
        {
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            ct=0;
            dfs(i);
            ans=sub(ans,binpow(ct,k));
        }
    cout<<ans;
    return 0;
}