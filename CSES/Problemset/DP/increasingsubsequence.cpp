#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[200001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l,r,m,b=1e9+1,k;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        dp[i+1]=b;
        l=0;r=i;
        while (l<r)
        {
            m=l+(r-l)/2+1;
            if (dp[m]<k)
                l=m;
            else
                r=m-1;
        }
        dp[l+1]=min(dp[l+1],k);
    }
    for (int i=n;i;--i)
        if (dp[i]<b)
        {
            cout<<i;
            return 0;
        }
    return 0;
}