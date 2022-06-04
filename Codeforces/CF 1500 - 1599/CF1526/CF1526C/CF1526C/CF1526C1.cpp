#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    vector<ll> dp(2001, -1e18);
    dp[0]=0;
    while (n--)
    {
        cin>>k;
        for (int i=2000;i>0;--i)
            if (dp[i-1]>=0&&dp[i-1]+k>=0)
                dp[i]=max(dp[i],dp[i-1]+k);
    }
    for (int i=2000;i>=0;--i)
        if (dp[i]>=0)
        {
            cout<<i;
            return 0;
        }
    return 0;
}