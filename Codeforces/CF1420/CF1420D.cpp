#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int> 
#define f first
#define s second
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int mod = 998244353;
ll f[300001];

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

ll choose(ll n, ll k)
{
    if (k>n)
        return 0;
    return (f[n]*binpow((f[k]*f[n-k])%mod,mod-2))%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,l,r,c=0,last=0,x;
    ll ans=0;
    f[0]=1;
    for (int i=1;i<300001;++i)
        f[i]=(f[i-1]*i)%mod;
    cin>>n>>k;
    priority_queue<int,vector<int>,greater<int>> q;
    map<int,vector<int>> added;
    map<int,vector<int>> removed;
    for (int i=0;i<n;++i)
    {
        cin>>l>>r;
        added[l].push_back(i);
        removed[r].push_back(i);
        q.push(l);
        q.push(r);
    }
    set<int> pure;
    while (!q.empty())
    {
        x=q.top();q.pop();
        if (x==last)
            continue;
        last=x;
        for (int i : added[x])
            pure.insert(i);
        c+=sz(added[x]);
        if (c>=k)
        {
            ans+=choose(c,k)+mod-choose(c-sz(pure),k);
            ans%=mod;
            //cout<<x<<" "<<ans<<"\n";
            pure.clear();
        }
        for (int i : removed[x])
            if (pure.find(i)!=pure.end())
                pure.erase(i);
        c-=sz(removed[x]);
    }
    cout<<ans;
    return 0;
}