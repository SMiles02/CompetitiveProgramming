#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
ll dp[1001][1001];

ll rect(int a, int b, int c, int d)
{
    return dp[c][d]-dp[a-1][d]-dp[c][b-1]+dp[a-1][b-1];
}

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    ll ans=-1e18;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            cin>>k;
            dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+k;
        }
    for (int a=1;a<=n;++a)
        for (int b=a;b<=n;++b)
            for (int c=1;c<=n;++c)
                for (int d=c;d<=n;++d)
                    ans=max(ans,rect(1,a,n,b)+rect(c,1,d,n)-rect(c,a,d,b));
    cout<<ans;
    return 0;
}