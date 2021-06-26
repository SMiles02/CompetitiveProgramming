#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 1e9+7;
ll ans,tot;

ll calc(ll x)
{
    return ((x*(x-1))/2)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    ll n=sz(s),p=1,cur;
    reverse(s.begin(), s.end());
    ans+=((calc(n)*(s[0]-'0'))%mod);
    for (int i=1;i<n;++i)
    {
        tot+=(p*i);
        tot%=mod;
        cur=tot;
        p*=10;
        p%=mod;
        cur+=p*calc(n-i);
        cur%=mod;
        ans+=(cur*(s[i]-'0'));
        ans%=mod;
    }
    cout<<ans;
    return 0;
}