#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
int mod=998244353;
 
ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a,b/2);
    res*=res;
    res%=mod;
    if (b%2)
        return (res*a)%mod;
    return res;
}
 
ll mult(ll a, ll b)
{
    return (a*b)%mod;
}
 
ll sum(ll a, ll b)
{
    return (a+b)%mod;
}
 
ll choosing[1000001];
int picking[1000001];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x;
    ll cur,a,ans=0;
    cin>>n;
    a=binpow(n,mod-2);
    for (int c=0;c<n;++c)
    {
        cin>>k;
        cur=mult(binpow(k,mod-2),a);
        for (int i=0;i<k;++i)
        {
            cin>>x;
            ++picking[x];
            choosing[x]=sum(choosing[x],cur);
        }
    }
    for (int i=1;i<1000001;++i)
        ans=sum(mult(choosing[i],mult(picking[i],a)),ans);
    cout<<ans%mod;
    return 0;
}