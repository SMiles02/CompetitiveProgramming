#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll dp[5001][5001];

ll max(ll a, ll b)
{
    if (a>b) return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,x;
    cin>>n>>m>>k;
    ll prefix[n+1];
    prefix[0]=0;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        prefix[i+1]=prefix[i]+x;
    }
    for (int i=m;i<=n;++i)
    {
        for (int j=1;j<=k;++j)
        {
            dp[i][j]=max(dp[i-m][j-1]+prefix[i]-prefix[i-m],dp[i-1][j]);
            //cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<"\n";
        }
    }
    cout<<dp[n][k];
    return 0;
}