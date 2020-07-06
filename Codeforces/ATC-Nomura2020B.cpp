#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
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
    string s;
    cin>>s;
    n=sz(s);
    /**int dp[n][2];
    for (int i=0;i<n;++i)
        for (int j=0;j<2;++j)
            dp[i][j]=-1e9;
    if (s[0]=='D')
        dp[0][0]=1;
    else if (s[0]=='P')
        dp[0][1]=0;
    else
    {
        dp[0][0]=1;
        dp[0][1]=0;
    }
    for (int i=1;i<n;++i)
    {
        if (s[i]=='D')
            dp[i][0]=max(dp[i-1][0]+1,dp[i-1][1]+2);
        else if (s[i]=='P')
            dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
        else
        {
            dp[i][0]=max(dp[i-1][0]+1,dp[i-1][1]+2);
            dp[i][1]=max(dp[i-1][0],dp[i-1][1]);
        }
    }
    cout<<max(dp[n-1][0],dp[n-1][1]);**/
    for (int i=0;i<n;++i)
    {
        if (s[i]=='?')
            cout<<"D";
        else
            cout<<s[i];
    }
    return 0;
}