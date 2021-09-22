//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int MOD = 1e9+7, N = 2e5+7;
int f[N];

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int dv(int x, int y)
{
    return mul(x,binpow(y,MOD-2));
}

int c(int x, int y)
{
    return dv(f[x],mul(f[y],f[x-y]));
}

void solve()
{
    int n,k,tmp=0;
    cin>>n>>k;
    int dp[k+1][2];
    dp[0][0]=1;
    dp[0][1]=0;
    for (int i=0;i<=n;i+=2)
        tmp=add(tmp,c(n,i));
    if (n&1)
        tmp=add(tmp,1);
    else
        tmp=add(tmp,MOD-1);
    //cout<<"tmp: "<<tmp<<"\n";
    for (int i=1;i<=k;++i)
    {
        dp[i][0]=mul(dp[i-1][0],tmp);
        dp[i][1]=add(mul(dp[i-1][1],binpow(2,n)),mul(dp[i-1][0],(n%2==0)));
        //cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    }
    cout<<add(dp[k][0],dp[k][1])<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0]=1;
    for (int i=1;i<N;++i)
        f[i]=mul(f[i-1],i);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}