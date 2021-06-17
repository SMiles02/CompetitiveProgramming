#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9+9;
int dp[1<<20];

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l,r,m;
    ll d;
    cin>>n>>d;
    ll a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    dp[0]=1;
    for (int i=1;i<n;++i)
    {
        if (a[i]>a[i-1]+d)
        {
            dp[i]=dp[i-1];
            continue;
        }
        l=0;r=i-1;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (a[i]>a[m]+d)
                l=m+1;
            else
                r=m;
        }
        dp[i]=mul(dp[i-1],i-l+1);
    }
    cout<<dp[n-1];
    return 0;
}