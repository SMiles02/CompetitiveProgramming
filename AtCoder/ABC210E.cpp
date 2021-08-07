#include <bits/stdc++.h>
#define ll long long
using namespace std;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,x,l,r,mid;
    cin>>n>>m;
    array<int,2> a[m];
    for (int i=0;i<m;++i)
        cin>>a[i][1]>>a[i][0];
    sort(a,a+m);
    vector<int> d;
    for (int i=1;i*i<=n;++i)
        if (n%i==0)
        {
            d.push_back(i);
            if (n!=i*i)
                d.push_back(n/i);
        }
    sort(d.begin(), d.end());
    k=d.size();
    vector<ll> dp(k,1e18);
    dp[k-1]=0;
    for (int i=0;i<m;++i)
    {
        for (int j=0;j<k;++j)
        {
            x=gcd(d[j],a[i][1]);
            l=0;r=j;
            while (l<r)
            {
                mid=l+(r-l)/2;
                if (d[mid]<x)
                    l=mid+1;
                else
                    r=mid;
            }
            dp[l]=min(dp[l], dp[j]+1LL*a[i][0]*(d[j]-d[l]));
        }
    }
    if (dp[0]==1e18)
        dp[0]=-1;
    cout<<dp[0];
    return 0;
}