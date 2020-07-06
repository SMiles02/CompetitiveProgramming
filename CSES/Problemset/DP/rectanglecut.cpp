#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[501][501];
bool done[501][501];

int solve(int x, int y)
{
    if (x==y)
        return 0;
    if (done[x][y])
        return dp[x][y];
    int ans=1000000000;
    for (int i=1;i<x;++i)
        ans=min(ans,solve(i,y)+solve(x-i,y));
    for (int i=1;i<y;++i)
        ans=min(ans,solve(x,i)+solve(x,y-i));
    done[x][y]=1;
    done[y][x]=1;
    dp[x][y]=ans+1;
    dp[y][x]=ans+1;
    return ans+1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b;
    cin>>a>>b;
    cout<<solve(a,b);
    return 0;
}