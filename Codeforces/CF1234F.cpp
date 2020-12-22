#include <bits/stdc++.h>
using namespace std;

int dp[(1<<20)];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,ans=0;
    string s;
    cin>>s;
    n=s.size();
    for (int i=0;i<n;++i)
    {
        x=0;
        for (int j=0;j<20&&i+j<n;++j)
        {
            x^=(1<<(s[i+j]-'a'));
            y=__builtin_popcount(x);
            if (y<=j)
                break;
            dp[x]=y;
        }
    }
    for (int i=1;i<(1<<20);++i)
    {
        for (int j=0;j<20;++j)
            if (!((1<<j)&i))
                dp[(1<<j)^i]=max(dp[(1<<j)^i],dp[i]);
        ans=max(ans,dp[i]+dp[((1<<20)-1)^i]);
    }
    cout<<ans;
    return 0;
}