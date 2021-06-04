#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

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

int dp[2002][2002];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=n-2;i>=0;--i)
    {
        if ((i+m-1)&1)
        {
            if (s[i+1][m-1]=='+')
                dp[i][m-1]=dp[i+1][m-1]-2;
            else
                dp[i][m-1]=dp[i+1][m-1]+2;
        }
        else
        {
            if (s[i+1][m-1]=='+')
                dp[i][m-1]=dp[i+1][m-1]+2;
            else
                dp[i][m-1]=dp[i+1][m-1]-2;
        }
    }
    for (int j=m-2;j>=0;--j)
    {
        if ((j+n-1)&1)
        {
            if (s[n-1][j+1]=='+')
                dp[n-1][j]=dp[n-1][j+1]-2;
            else
                dp[n-1][j]=dp[n-1][j+1]+2;
        }
        else
        {
            if (s[n-1][j+1]=='+')
                dp[n-1][j]=dp[n-1][j+1]+2;
            else
                dp[n-1][j]=dp[n-1][j+1]-2;
        }
    }
    for (int i=n-2;i>=0;--i)
        for (int j=m-2;j>=0;--j)
        {
            if (s[i+1][j]=='+')
                x=2;
            else
                x=-2;
            if (s[i][j+1]=='+')
                y=2;
            else
                y=-2;
            if ((i+j)&1)
                dp[i][j]=min(dp[i+1][j]-x,dp[i][j+1]-y);
            else
                dp[i][j]=max(dp[i+1][j]+x,dp[i][j+1]+y);
        }
    // for (int i=0;i<n;++i)
    // {
    //     for (int j=0;j<m;++j)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    if (dp[0][0]>0)
        cout<<"Takahashi";
    else if (dp[0][0]<0)
        cout<<"Aoki";
    else
        cout<<"Draw";
    return 0;
}