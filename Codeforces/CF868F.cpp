#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+7, K = 24;
const ll INF = 1e18;
int a[N], ct[N];
ll dp[K][N];

void solve(int i, int l, int r, int optL, int optR, int x, int y, ll z)
{
    if (l>r)
        return;
    int m=l+(r-l)/2, k=-1,X=x,Y=y, tmp;
    ll best=INF, cur=z;
    tmp=min(optR,m);
    while (tmp+1<X)
        cur+=ct[a[--X]]++;
    while (X<=tmp)
        cur-=--ct[a[X++]];
    while (m<Y)
        cur-=--ct[a[Y--]];
    while (Y<m)
        cur+=ct[a[++Y]]++;
    for (int j=tmp;j>=optL;--j)
    {
        cur+=ct[a[j]]++;
        --X;
        if (dp[i-1][j-1]+cur<=best)
        {
            best=dp[i-1][j-1]+cur;
            k=j;
        }
    }
    dp[i][m]=best;
    solve(i,l,m-1,optL,k,X,Y,cur);
    solve(i,m+1,r,k,optR,X,Y,cur);
    while (x<X)
        ++ct[a[--X]];
    while (X<x)
        --ct[a[X++]];
    while (y<Y)
        --ct[a[Y--]];
    while (Y<y)
        ++ct[a[++Y]];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        dp[0][i]=INF;
    }
    ++ct[a[1+(n-1)/2]];
    for (int i=1;i<=k;++i)
        solve(i,1,n,1,n,1+(n-1)/2,1+(n-1)/2,0);
    cout<<dp[k][n];
    return 0;
}