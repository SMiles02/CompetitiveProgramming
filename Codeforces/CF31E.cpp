#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

ll dp[37][19];
string dp1[37][19];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    string s;
    cin>>s;
    dp1[0][0]="";
    for (int i=0;i<2*n;++i)
        for (int j=1;j<=n;++j)
            if (0<=i+1-j&&i+1-j<=n)
            {
                k=i+1-j;
                if (j>0)
                {
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j-1]+binpow(10,n-j)*(s[i]-'0'));
                    dp1[i+1][j]=dp1[i][j-1]+'H';
                }
                if (k>0&&dp[i+1][j]<=dp[i][j]+binpow(10,n-k)*(s[i]-'0'))
                {
                    dp[i+1][j]=dp[i][j]+binpow(10,n-k)*(s[i]-'0');
                    dp1[i+1][j]=dp1[i][j]+'M';
                }
            }
    cout<<dp1[2*n][n];
    return 0;
}