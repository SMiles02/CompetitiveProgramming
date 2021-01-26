#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e4+5, mod = 1e9+7;
int dp[2][mn];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int sub(int a, int b)
{
    a-=b;
    if (a<0)
        a+=mod;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    dp[0][sz(s)]=1;
    for (int _=0;_<n;++_)
    {
        dp[1][0]=add(dp[0][0],dp[0][1]);
        for (int i=1;i+1<mn;++i)
            dp[1][i]=add(add(dp[0][i-1],dp[0][i-1]),dp[0][i+1]);
        for (int i=0;i<mn;++i)
        {
            dp[0][i]=dp[1][i];
            dp[1][i]=0;
        }
    }
    cout<<dp[0][0];
    return 0;
}