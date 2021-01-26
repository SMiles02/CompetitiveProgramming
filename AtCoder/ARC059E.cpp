#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 402, mod = 1e9+7;
int dp[2][mn],powPre[mn][mn];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int sub(int a, int b)
{
    //cout<<a<<" - "<<b<<" = ";
    a-=b;
    if (a<0)
        a+=mod;
    //cout<<a<<"\n";
    return a;
}

int mult(int a, int b)
{
    return (1LL*a*b)%mod;
}

ll binpow(ll a, int b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,c,x;
    cin>>n>>c;
    int a[n],b[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>b[i];
    for (int i=1;i<mn;++i)
    {
        x=1;
        for (int j=0;j<mn;++j)
        {
            powPre[i][j]=add(powPre[i-1][j],x);
            //cout<<powPre[i][j]<<" ";
            x=mult(x,i);
        }
        //cout<<"\n";
    }
    dp[0][0]=1;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<=c;++j)
            for (int k=0;k<=j;++k)
            {
                dp[1][j]=add(dp[1][j],mult(dp[0][k],sub(powPre[b[i]][j-k],powPre[a[i]-1][j-k])));
                //cout<<j<<" "<<k<<": "<<dp[0][k]<<" * ("<<powPre[b[i]][j-k]<<" - "<<powPre[a[i]-1][j-k]<<")\n";
                //cout<<j<<" "<<k<<": "<<dp[0][k]<<" * ("<<sub(powPre[b[i]][j-k],powPre[a[i]-1][j-k])<<")\n";
            }
        dp[0][0]=dp[1][0];
        dp[1][0]=0;
        for (int j=1;j<=c;++j)
        {
            dp[0][j]=dp[1][j];
            dp[1][j]=0;
        }
    }
    /**for (int i=0;i<=c;++i)
        cout<<dp[0][i]<<" ";
    cout<<"\n";**/
    cout<<dp[0][c];
    return 0;
}