#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool dp[5000001][2];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    int t,a,b,ans=0;
    cin>>t>>a>>b;
    dp[0][0]=1;
    for (int i=0;i<=t;++i)
    {
        if (dp[i][0])
        {
            ans=i;
            if (i+a<=t)
                dp[i+a][0]=1;
            if (i+b<=t)
                dp[i+b][0]=1;
            dp[i/2][1]=1;
        }
    }
    for (int i=1;i<=t;++i)
    {
        if (dp[i][1])
        {
            ans=max(ans,i);
            if (i+a<=t)
                dp[i+a][1]=1;
            if (i+b<=t)
                dp[i+b][1]=1;
        }
    }
    cout<<ans;
	return 0;
}