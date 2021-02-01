#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    ll a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int dp[n];
    dp[0]=0;
    for (int i=1;i<n;++i)
    {
        if (a[i]-a[i-1]>5)
        {
            dp[i]=dp[i-1];
        }
        else
        {
            dp[i]=dp[i-1]+1;
        }
    }
    for (int i=0;i+k-1<n;++i)
    {
        if (dp[i+k-1]-dp[i]>=k-1)
        {
            ll ans=0;
            for (int j=i;j<i+k;++j)
            {
                ans+=a[j];
            }
            cout<<ans;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}