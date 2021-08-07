//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
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

const int N = 5005, MOD = 998244353;
vector<int> e[N];
int dp[N][N];

int add(int a, int b)
{
    a+=b;
    while (a>=MOD)
        a-=MOD;
    return a;
}

int sub(int a, int b)
{
    //cerr<<a<<" "<<b<<" = "<<add(add(a,0),MOD-b)<<"\n";
    return add(a,MOD-b);
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,x,y,s;
    cin>>n>>m>>k;
    while (m--)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dp[0][1]=1;
    for (int i=1;i<=k;++i)
    {
        s=0;
        for (int j=1;j<=n;++j)
        {
            s=add(s,dp[i-1][j]);
            //cout<<dp[i-1][j]<<" ";
        }
        //cout<<s<<"!\n";
        for (int j=1;j<=n;++j)
        {
            dp[i][j]=sub(s,dp[i-1][j]);
            for (int v : e[j])
                dp[i][j]=sub(dp[i][j],dp[i-1][v]);
            //cout<<i<<" "<<j<<": "<<dp[i][j]<<"\n";
        }
    }
    cout<<dp[k][1];
    return 0;
}