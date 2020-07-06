#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1000000007;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
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
    ll ans;
    string s;
    cin>>s;
    n=sz(s);
    ll factorial[1000001];
    factorial[0]=1;
    for (int i=1;i<1000001;++i)
    {
        factorial[i]=factorial[i-1]*i;
        factorial[i]%=mod;
    }
    map<char,int> m;
    for (int i=0;i<n;++i)
    {
        ++m[s[i]];
    }
    ans=factorial[n];
    for (char c='a';c<='z';++c)
    {
        ans*=binpow(factorial[m[c]],mod-2);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}