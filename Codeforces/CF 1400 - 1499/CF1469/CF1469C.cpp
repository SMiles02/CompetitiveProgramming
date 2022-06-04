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

void solve()
{
    int n,k,h;
    cin>>n>>k;
    int dp[n][2];
    bool bad=0;
    cin>>h;
    dp[0][0]=h+k;
    dp[0][1]=h+k;
    for (int i=1;i<n;++i)
    {
        cin>>h;
        dp[i][0]=max(h+k,dp[i-1][0]+1-k);
        dp[i][1]=min(h+2*k-1,dp[i-1][1]+k-1);
        if (dp[i][1]<dp[i][0])
            bad=1;
    }
    if (bad||dp[n-1][0]>h+k)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}