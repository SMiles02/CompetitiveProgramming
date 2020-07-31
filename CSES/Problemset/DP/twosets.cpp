#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1e9+7;
int dp[62625];

int add(int a, int b)
{
    if (a+b>mod)
        return a+b-mod;
    return a+b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    if (n%4==1||n%4==2)
    {
        cout<<0;
        return 0;
    }
    dp[0]=1;
    k=n*(n+1);
    k/=4;
    for (int j=1;j<=n;++j)
        for (int i=k;i-j>=0;--i)
            dp[i]=add(dp[i],dp[i-j]);
    if (dp[k]&1)
        dp[k]+=mod;
    cout<<dp[k]/2;
    return 0;
}