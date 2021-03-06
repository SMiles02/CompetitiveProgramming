#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    string s[n];
    int dp[n][n][2];
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
    }
    dp[0][0][0]=0;
    dp[0][0][1]=0;
    for (int i=1;i<n;++i)
    {
        if (s[0][i]=='*')
        {
            dp[0][i][0]=n*n;
        }
        else
        {
            dp[0][i][0]=dp[0][i-1][0];
        }
        if (s[i][0]=='*')
        {
            dp[i][0][1]=n*n;
        }
        else
        {
            dp[i][0][1]=dp[i-1][0][1];
        }
        dp[0][i][1]=n*n;
        dp[i][0][0]=n*n;
    }
    for (int i=1;i<n;++i)
    {
        for (int j=1;j<n;++j)
        {
            dp[i][j][0]=min(dp[i][j-1][0],min(dp[i][j-1][1]+1,min(dp[i-1][j][0]+1,dp[i-1][j][1]+1)));
            dp[i][j][1]=min(dp[i][j-1][1]+1,min(dp[i][j-1][0],min(dp[i-1][j][0],dp[i-1][j][1])+1));
            if (s[i][j]=='*')
            {
                dp[i][j][0]=n*n;
                dp[i][j][1]=n*n;
            }
        }
    }
    cout<<min(dp[n-1][n-1][0],dp[n-1][n-1][1]);
    return 0;
}