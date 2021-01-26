#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 401, mod = 1e9+7;
int dp[2][mn],pre[mn];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int sub(int a, int b)
{
    a-=b;
    if (a<0)
        a+=mod;
    return 0;
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
    dp[0][0]=1;
    for (int i=0;i<n;++i)
    {
        for (int j=a[i];j<=b[i];++j)
        {
            x=1;
            for (int k=0;k<=c;++k)
            {
                for (int l=k;l<=c;++l)
                    dp[1][l]=add(dp[1][l],mult(dp[0][l-k],x));
                x=mult(x,j);
            }
        }
        pre[0]=dp[0][0]=dp[1][0];
        dp[1][0]=0;
        for (int j=1;j<=c;++j)
        {
            dp[0][j]=dp[1][j];
            //pre[j]=add(pre[j-1],dp[0][j]);
            dp[1][j]=0;
        }
    }
    for (int i=0;i<=c;++i)
        cout<<dp[0][i]<<" ";
    cout<<"\n";
    cout<<dp[0][c];
    return 0;
}