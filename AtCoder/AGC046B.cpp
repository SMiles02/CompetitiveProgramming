#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=998244353;
ll dp[3001][3001];

ll sum(ll x, ll y)
{
    if (x+y>mod)
        return x+y-mod;
    return x+y;
}

ll pos(ll x)
{
    if (x<0)
        x+=mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c,d,x,y;
    cin>>a>>b>>c>>d;
    dp[0][0]=1;
    x=c-a;y=d-b;
    for (int i=1;i<=x;++i)
    {
        dp[i][0]=(dp[i-1][0]*b)%mod;
        cout<<"dp["<<i<<"]["<<0<<"] = "<<dp[i][0]<<"\n";
    }
    for (int j=1;j<=y;++j)
    {
        dp[0][j]=(dp[0][j-1]*a)%mod;
        cout<<"dp["<<0<<"]["<<j<<"] = "<<dp[0][j]<<"\n";
    }
    for (int i=1;i<=x;++i)
        for (int j=1;j<=y;++j)
        {
            dp[i][j]=pos(sum((dp[i-1][j]*(j+b))%mod,(dp[i][j-1]*(i+a))%mod)-((i+a-1)*(j+b-1)));
            cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<"\n";
        }
    cout<<dp[x][y];
    return 0;
}