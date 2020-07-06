#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin>>n>>x;
    ll dp[x+1]={0};
    dp[0]=1;
    int coins[n];
    for (int i=0;i<n;++i)
    {
        cin>>coins[i];
    }
    for (int i=1;i<=x;++i)
    {
        for (int j=0;j<n;++j)
        {
            if (i-coins[j]>=0)
            {
                dp[i]+=dp[i-coins[j]];
                dp[i]%=1000000007;
            }
        }
    }
    cout<<dp[x];
    return 0;
}