#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 1e9+7;
ll f[101];
string s[100];

ll mul(ll a, ll b)
{
    return (a*b)%mod;
}

void solve()
{
    int n,k,c;
    ll ans=1;
    string t;
    cin>>n>>k;
    cin>>t;
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
        c=0;
        for (int j=0;j<n;++j)
            if (s[i][j]=='1')
                ++c;
        if (t[i]=='R')
            ++c;
        ans=mul(ans,f[max(c,1)]);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    f[0]=1;
    for (int i=1;i<=100;++i)
        f[i]=mul(f[i-1],i);
    while (t--)
        solve();
    return 0;
}