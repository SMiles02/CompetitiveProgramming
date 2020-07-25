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
    int n,k,l;
    cin>>n>>k>>l;
    int a[n+1];
    int b[2*k];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<=k;++i)
        b[i]=i;
    for (int i=k+1;i<2*k;++i)
        b[i]=b[i-1]-1;
    bool dp[n+1][2*k];
    for (int i=0;i<2*k;++i)
        dp[0][i]=1;
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<2*k;++j)
        {
            if (a[i]+b[j]>l)
                dp[i][j]=0;
            else
                dp[i][j]=(dp[i-1][(j+2*k-1)%(2*k)]);
            //cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<"\n";
        }
        for (int _=0;_<2;++_)
            for (int j=0;j<2*k;++j)
                if (a[i]+b[j]<=l)
                    dp[i][j]=(dp[i][j]|dp[i][(j+2*k-1)%(2*k)]);
    }
    for (int i=0;i<2*k;++i)
        if (dp[n][i])
        {
            cout<<"Yes\n";
            return;
        }
    cout<<"No\n";
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