#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

const int N = 2003;
int n,m,dp[N][N],C[N],ol[N][N],p[N][N],ct[N],l,r,t;
char s[N][N];
bitset<N> done[N];
vector<array<int,2>> d = {{0,-1},{0,1},{-1,0},{1,0}};

bool ok(int x, int y)
{
    if (0<x&&0<y&&x<=n&&y<=m&&s[x][y]!='.'&&!done[x][y])
        return 1;
    return 0;
}

void dfs(int x, int y)
{
    done[x][y]=1;
    l=min(l,y);
    r=max(r,y);
    t+=(s[x][y]-'0');
    for (auto i : d)
        if (ok(x+i[0],y+i[1]))
            dfs(x+i[0],y+i[1]);
}

void solve(int i, int l, int r, int optL, int optR)
{
    if (l>r)
        return;
    int m=l+(r-l)/2,best=-1,k=-1;
    for (int j=optL;j<=m;++j)
        if (best<dp[i-1][j-1]+C[m]-ol[j-1][m])
        {
            best=dp[i-1][j-1]+C[m]-ol[j-1][m];
            k=j;
        }
    dp[i][m]=best;
    solve(i,l,m-1,optL,k);
    solve(i,m+1,r,k,optR);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            cin>>s[i][j];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (ok(i,j))
            {
                t=0;
                l=j;
                r=j;
                dfs(i,j);
                ct[l]+=t;
                ct[r+1]-=t;
                p[l][l]+=t;
                p[l][r+1]-=t;
            }
    for (int i=1;i<=m;++i)
    {
        ct[i]+=ct[i-1];
        C[i]+=ct[i];
    }
    for (int i=1;i<=m;++i)
        for (int j=i;j<=m;++j)
        {
            p[i][j]+=p[i][j-1];
            ol[i][j]=p[i][j]+ol[i-1][j];
        }
    for (int i=1;i<=m;++i)
    {
        solve(i,1,m,1,m);
        for (int j=2;j<=m;++j)
            dp[i][j]=max(dp[i][j-1],dp[i][j]);
        cout<<dp[i][m]<<"\n";
    }
    return 0;
}