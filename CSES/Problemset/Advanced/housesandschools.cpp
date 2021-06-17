#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3003, K = 3003;
const ll INF = 1e18;
int n, k, a[N];
ll dp[K][N], p[N][2], C[N][N];

void solve(int i, int l, int r, int optL, int optR)
{
    if (l>r)
        return;
    int m=l+(r-l)/2,k=-1;
    ll best=INF;
    for (int j=optL;j<=min(optR,m);++j)
        if (dp[i-1][j-1]+C[j][m]<best)
        {
            best=dp[i-1][j-1]+C[j][m];
            k=j;
        }
    dp[i][m]=best;
    solve(i,l,m-1,optL,k);
    solve(i,m+1,r,k,optR);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    int cur;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        dp[0][i]=INF;
        p[i][0]=p[i-1][0]+a[i];
        p[i][1]=p[i-1][1]+1LL*i*a[i];
    }
    for (int i=1;i<=n;++i)
    {
        cur=i;
        for (int j=i+1;j<=n;++j)
        {
            while (cur<j&&(p[j][1]-p[cur][1]-(p[j][0]-p[cur][0])*(cur+1))+((p[cur+1][0]-p[i-1][0])*(cur+1)-p[cur+1][1]+p[i-1][1])<=(p[j][1]-p[cur-1][1]-(p[j][0]-p[cur-1][0])*cur)+((p[cur][0]-p[i-1][0])*cur-p[cur][1]+p[i-1][1]))
                ++cur;
            C[i][j]=(p[j][1]-p[cur-1][1]-(p[j][0]-p[cur-1][0])*cur)+((p[cur][0]-p[i-1][0])*cur-p[cur][1]+p[i-1][1]);
        }
    }
    for (int i=1;i<=k;++i)
        solve(i,1,n,1,n);
    cout<<dp[k][n];
    return 0;
}