#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b, int mod) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a,b/2,mod);
    res*=res;
    res%=mod;
    if (b % 2)
    {
        return (res*a)%mod;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll a,b,c;
    cin>>n;
    while (n--)
    {
        cin>>a>>b>>c;
        cout<<binpow(a,binpow(b,c,1000000006),1000000007)<<"\n";
    }
    return 0;
}