#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[5000];

void solve()
{
    int n;
    cin>>n;
    ll x,y;
    int t[n],s[n];
    for (int i=0;i<n;++i)
    {
        cin>>t[i];
        dp[i]=0;
    }
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
        for (int j=i-1;j>=0;--j)
            if (t[i]!=t[j])
            {
                x=dp[i];
                y=dp[j];
                dp[i]=max({dp[i],y+abs(s[i]-s[j])});
                dp[j]=max({dp[j],x+abs(s[i]-s[j])});
            }
    for (int i=1;i<n;++i)
        dp[i]=max({dp[i-1],dp[i]});
    cout<<dp[n-1]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}