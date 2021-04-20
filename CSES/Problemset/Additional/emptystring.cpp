#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[500][500];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int mul(int a, int b)
{
    return (1LL*a*b)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    for (int i=0;i+1<n;++i)
        if (s[i]==s[i+1])
            dp[i][i+1]=1;
    for (int i=n-1;i>=0;--i)
        for (int j=i+3;j<n;j+=2)
        {
            if (s[i]==s[j])
                dp[i][j]=dp[i+1][j-1];
            for (int k=i+1;k<j;k+=2)
                dp[i][j]=add(dp[i][j],mul(dp[i][k],dp[k+1][j]));
        }
    cout<<dp[0][n-1];
    return 0;
}