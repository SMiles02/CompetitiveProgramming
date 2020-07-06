#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

ll min(ll a, ll b)
{
    if (a>b) return b;
    return a;
}

ll funct(ll n, ll x)
{
    ll ans=0;
    while (n)
    {
        ans+=(n/x);
        n/=x;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,b,ans=2*binpow(10,18),s,cur;
    cin>>n>>b;
    s=sqrt(b);
    for (int i=2;i<=s;++i)
    {
        if (!(b%i))
        {
            cur=0;
            while (!(b%i))
            {
                ++cur;
                b/=i;
            }
            ans=min(ans,funct(n,i)/cur);
            s=sqrt(b);
        }
    }
    if (b>1)
    {
        ans=min(ans,funct(n,b));
    }
    cout<<ans;
    return 0;
}