#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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
    int n,k,t,l,r,m,ans=0;
    cin>>n>>k;
    int a[n+1];
    a[0]=0;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>t;
    sort(a,a+n+1);
    int dp[n+1];
    dp[0]=0;
    for (int i=1;i<=n;++i)
    {
        l=1;r=i;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (a[i]-k<=a[m])
                r=m;
            else
                l=m+1;
        }
        ans=max(ans,i-r+1+dp[r-1]);
        dp[i]=max(i-r+1,dp[i-1]);
    }
    cout<<ans<<"\n";
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