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
    int n,k;
    cin>>n>>k;
    int h[n];
    int dp[n];
    for (int i=0;i<n;++i)
    {
        cin>>h[i];
    }
    dp[0]=0;
    for (int i=1;i<n;++i)
    {
        dp[i]=dp[i-1]+abs(h[i]-h[i-1]);
        for (int j=2;j<=k&&i-j>=0;++j)
        {
           dp[i]=min(dp[i-j]+abs(h[i]-h[i-j]),dp[i]); 
        }
    }
    cout<<dp[n-1];
    return 0;
}