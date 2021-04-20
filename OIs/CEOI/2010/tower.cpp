#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6+7, mod = 1e9+9;
ll dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,d,l,r,m;
    cin>>n>>d;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    dp[0]=1;
    for (int i=1;i<n;++i)
    {
        if (a[i-1]+d<a[i])
        {
            dp[i]=dp[i-1];
            continue;
        }
        l=0;r=n-1;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (a[m]+d<a[i])
                l=m+1;
            else
                r=m;
        }
        dp[i]=dp[i-1]*(i-l+1);
        dp[i]%=mod;
    }
    cout<<dp[n-1];
    return 0;
}