#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l,r;
    ll mods[3];
    cin>>n>>l>>r;
    ll dp[n][3];
    ll MOD=1000000007;
    mods[0]=((r-l+1)/3);
    mods[1]=((r-l+1)/3);
    mods[2]=((r-l+1)/3);
    if ((r-l+1)%3==1)
    {
        ++mods[l%3];
    }
    if ((r-l+1)%3==2)
    {
        ++mods[l%3];
        ++mods[(l+1)%3];
    }
    for (int i=0;i<3;++i)
    {
        dp[0][i]=mods[i];
    }
    for (int i=1;i<n;++i)
    {
        dp[i][0]=((dp[i-1][0]*mods[0])+(dp[i-1][1]*mods[2])+(dp[i-1][2]*mods[1]))%MOD;
        dp[i][1]=((dp[i-1][0]*mods[1])+(dp[i-1][1]*mods[0])+(dp[i-1][2]*mods[2]))%MOD;
        dp[i][2]=((dp[i-1][0]*mods[2])+(dp[i-1][1]*mods[1])+(dp[i-1][2]*mods[0]))%MOD;
    }
    cout<<dp[n-1][0];
    return 0;
}