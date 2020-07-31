#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll dp[5001][5001];
ll a[5001];
ll p[5001];

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
        dp[i][i]=a[i];
    }
    for (int j=1;j<n;++j)
        for (int i=1;i+j<=n;++i)
            dp[i][i+j]=max(a[i]+p[i+j]-p[i]-dp[i+1][i+j],a[i+j]+p[i+j-1]-p[i-1]-dp[i][i+j-1]);
    cout<<dp[1][n];
    return 0;
}