#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[5001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    string s,t;
    cin>>s;
    cin>>t;
    if (sz(s)>sz(t))
        swap(s,t);
    n=sz(s);
    m=sz(t);
    for (int i=1;i<=n;++i)
        dp[i]=1000000;
    for (int i=0;i<m;++i)
    {
        for (int j=n;j;--j)
        {
            if (t[i]==s[j-1])
                dp[j]=min(dp[j-1],dp[j]);
            else
                dp[j]=min(dp[j-1]+1,dp[j]);
        }
    }
    cout<<dp[n]+m-n;
    return 0;
}