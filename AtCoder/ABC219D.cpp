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

const int INF = 1e9, N = 602;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,a,b,ans=1e9;
    cin>>n;
    cin>>x>>y;
    vector<vector<vector<int>>> dp(2,vector<vector<int>>(N,vector<int>(N,INF)));
    dp[0][0][0]=0;
    dp[1][0][0]=0;
    for (int i=0;i<n;++i)
    {
        cin>>a>>b;
        for (int j=a;j<N;++j)
            for (int k=b;k<N;++k)
                dp[1][j][k]=min(dp[1][j][k],dp[0][j-a][k-b]+1);
        for (int j=N-2;j>=0;--j)
            for (int k=N-2;k>=0;--k)
                dp[1][j][k]=min({dp[1][j][k],dp[1][j+1][k],dp[1][j][k+1]});
        dp[0]=dp[1];
    }
    for (int i=x;i<N;++i)
        for (int j=y;j<N;++j)
            ans=min(ans,dp[0][i][j]);
    if (ans==INF)
        ans=-1;
    cout<<ans;
    return 0;
}