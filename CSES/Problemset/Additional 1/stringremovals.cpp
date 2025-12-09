#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7, N = 5e5+1;
int dp[N][26], e[N];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    int n=s.size(),ans=mod-1;
    for (int j=0;j<26;++j)
        dp[n][j]=n+1;
    for (int i=n-1;i>=0;--i)
    {
        for (int j=0;j<26;++j)
            dp[i][j]=dp[i+1][j];
        dp[i][s[i]-'a']=i+1;
    }
    e[0]=1;
    for (int i=0;i<=n;++i)
    {
        ans=add(ans,e[i]);
        for (int j=0;j<26;++j)
            e[dp[i][j]]=add(e[dp[i][j]],e[i]);
    }
    cout<<ans;
    return 0;
}