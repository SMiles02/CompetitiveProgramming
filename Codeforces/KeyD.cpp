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
    cin>>n;
    int a[n];
    int b[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>b[i];
    int dp[n][2];
    for (int i=0;i<n;++i)
    {
        dp[i][0]=100;
        dp[i][1]=100;
    }
    dp[0][0]=0;
    dp[0][1]=1;
    for (int i=1;i<n;++i)
    {
        if (a[i-1]<=a[i])
            dp[i][0]=min(dp[i][0],dp[i-1][0]);
        if (a[i-1]<=b[i])
            dp[i][1]=min(dp[i][1],dp[i-1][0]+1);
        if (b[i-1]<=a[i])
            dp[i][0]=min(dp[i][0],dp[i-1][1]);
        if (b[i-1]<=b[i])
            dp[i][1]=min(dp[i][1],dp[i-1][1]+1);
    }
    if (min(dp[n-1][0],dp[n-1][1])<=n)
        cout<<min(dp[n-1][0],dp[n-1][1]);
    else
        cout<<-1;
    return 0;
}