#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 1e9+7;

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

ll div_mod(ll a, ll b)
{
    return (a*binpow(b,mod-2))%mod;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

const int mn = 2e5+1;
int pf[mn];
multiset<int> s[mn];

void sieve()
{
    for (int i=2;i<mn;i+=2)
        pf[i]=2;
    for (int i=3;i<mn;i+=2)
        if (!pf[i])
            for (int j=i;j<mn;j+=i)
                pf[j]=i;
}

vector<array<int,2>> getF(int k)
{
    int x,y;
    vector<array<int,2>> v;
    while (k>1)
    {
        x=pf[k];
        y=0;
        while (pf[k]==x)
        {
            ++y;
            k/=x;
        }
        v.push_back({x,y});
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y;
    cin>>n>>q;
    ll ans=0;
    int a[n+1];
    sieve();
    vector<array<int,2>> f;
    map<array<int,2>,int> m;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        ans=gcd(a[i],ans);
        f=getF(a[i]);
        for (auto j : f)
        {
            m[{i,j[0]}]=j[1];
            s[j[0]].insert(j[1]);
        }
    }
    while (q--)
    {
        cin>>x>>y;
        f=getF(y);
        for (auto i : f)
        {
            if (m[{x,i[0]}])
            {
                if (sz(s[i[0]])==n)
                    ans=div_mod(ans,binpow(i[0],*(s[i[0]].begin())));
                s[i[0]].erase(s[i[0]].lower_bound(m[{x,i[0]}]));
            }
            m[{x,i[0]}]+=i[1];
            s[i[0]].insert(m[{x,i[0]}]);
            if (sz(s[i[0]])==n)
                ans=(ans*binpow(i[0],*(s[i[0]].begin())))%mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}