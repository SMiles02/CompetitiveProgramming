#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+5, mod = 998244353;
int dp[N], d[N];

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
    int n,s=1;
    cin>>n;
    for (int i=2;i<=N;i+=2)
        for (int j=i*2;j<=N;j+=i)
            ++d[j];
    dp[0]=1;
    for (int i=1;i<=n;++i)
    {
        dp[i]=add(s,d[i*2]);
        s=add(s,dp[i]);
    }
    cout<<dp[n];
    return 0;
}