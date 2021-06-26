#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int lessThan(string a, string b) //a<b 1=>true, 0=>false
{
    int k=min(sz(a),sz(b));
    for (int i=0;i<k;++i)
    {
        if (a[i]<b[i])
        {
            return 1;
        }
        if (b[i]<a[i])
        {
            return 0;
        }
    }
    if (sz(a)>sz(b))
    {
        return 0;
    }
    return 1;
}

string backwards(string s)
{
    reverse(s.begin(), s.end());
    return s;
}

ll min(ll a, ll b)
{
    if (a>b)
    {
        return b;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    string s[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
    }
    ll dp[n][2];
    dp[0][0]=0;
    dp[0][1]=a[0];
    for (int i=1;i<n;++i)
    {
        dp[i][0]=1000000000000000000;
        dp[i][1]=1000000000000000000;
        if (lessThan(s[i-1],s[i]))
        {
            dp[i][0]=min(dp[i-1][0],dp[i][0]);
        }
        if (lessThan(backwards(s[i-1]),s[i]))
        {
            dp[i][0]=min(dp[i-1][1],dp[i][0]);
        }
        if (lessThan(s[i-1],backwards(s[i])))
        {
            dp[i][1]=min(dp[i-1][0],dp[i][1]);
        }
        if (lessThan(backwards(s[i-1]),backwards(s[i])))
        {
            dp[i][1]=min(dp[i-1][1],dp[i][1]);
        }
        dp[i][1]+=a[i];
    }
    if (dp[n-1][1]>=1000000000000000000&&dp[n-1][0]>=1000000000000000000)
    {
        cout<<-1;
    }
    else
    {
        cout<<min(dp[n-1][1],dp[n-1][0]);
    }
    return 0;
}