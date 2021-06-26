#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    string t;
    cin>>t;
    set<ll> s1;
    set<ll> s2;
    s1.insert(0);
    s2.insert(0);
    ll dp1[n+1];
    ll dp2[n+1];
    dp1[n]=0;
    dp2[n]=0;
    for (int i=n-1;i+1;--i)
    {
        if (i+2*(k+1)<=n)
            s1.erase(dp1[i+2*(k+1)]);
        if (i+k+2<=n)
            s2.erase(dp2[i+k+2]);
        cout<<i<<": beg = "<<*(s2.begin())<<"\n";
        if (t[i]=='1')
        {
            dp1[i]=min(*(s1.begin()),*(s2.begin()))+i+1;
            dp2[i]=*(s2.begin())+i+1;
        }
        else
        {
            dp1[i]=1e15;
            dp2[i]=*(s2.begin())+i+1;
        }
        s1.insert(dp1[i]);
        s2.insert(dp2[i]);
        cout<<i<<": "<<dp1[i]<<" "<<dp2[i]<<"\n";
    }
    ll ans=dp2[0];
    for (int i=0;i<min(n,k+1);++i)
        ans=min(ans,dp1[i]);
    cout<<ans;
    return 0;
}