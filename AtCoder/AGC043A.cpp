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
    int h,w;
    cin>>h>>w;
    int dp[h][w];
    string s[h];
    for (int i=0;i<h;++i)
    {
        cin>>s[i];
    }
    if (s[0][0]=='.')
    {
        dp[0][0]=0;
    }
    else
    {
        dp[0][0]=1;
    }
    for (int i=1;i<h;++i)
    {
        if (s[i][0]=='.')
        {
            dp[i][0]=dp[i-1][0];
        }
        else
        {
            dp[i][0]=dp[i-1][0]+1;
        }
    }
    for (int i=1;i<w;++i)
    {
        if (s[0][i]=='.')
        {
            dp[0][i]=dp[0][i-1];
        }
        else
        {
            dp[0][i]=dp[0][i-1]+1;
        }
    }
    for (int i=1;i<h;++i)
    {
        for (int j=1;j<w;++j)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
            if (s[i][j]=='#')
            {
                ++dp[i][j];
            }
        }
    }
    cout<<dp[h-1][w-1];
    return 0;
}