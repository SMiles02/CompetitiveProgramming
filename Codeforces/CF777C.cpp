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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q,l,r;
    cin>>n>>m;
    int a[n+1][m+1];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            cin>>a[i][j];
    int dp[n+1][m+1];
    int quickDP[n+1];
    vector<int> cur;
    for (int j=1;j<=m;++j)
    {
        cur.push_back(n);
        for (int i=n-1;i>=1;--i)
        {
            if (a[i][j]>a[i+1][j])
                while (sz(cur))
                {
                    dp[cur.back()][j]=i+1;
                    cur.pop_back();
                }
            cur.push_back(i);
        }
        while (sz(cur))
        {
            dp[cur.back()][j]=1;
            cur.pop_back();
        }
    }
    for (int i=1;i<=n;++i)
    {
        quickDP[i]=i;
        for (int j=1;j<=m;++j)
            quickDP[i]=min(quickDP[i],dp[i][j]);
    }
    cin>>q;
    while (q--)
    {
        cin>>l>>r;
        if (quickDP[r]<=l)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}