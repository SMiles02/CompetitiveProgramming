#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
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
    ll n,p,q,r,k;
    cin>>n>>p>>q>>r;
    ll dp[n][3];
    cin>>k;
    dp[0][0]=k*p;
    dp[0][1]=dp[0][0]+k*q;
    dp[0][2]=dp[0][1]+k*r;
    for (int i=1;i<n;++i)
    {
        cin>>k;
        dp[i][0]=max(dp[i-1][0],p*k);
        dp[i][1]=max(dp[i-1][1],dp[i][0]+q*k);
        dp[i][2]=max(dp[i-1][2],dp[i][1]+r*k);
    }
    cout<<dp[n-1][2];
    return 0;
}