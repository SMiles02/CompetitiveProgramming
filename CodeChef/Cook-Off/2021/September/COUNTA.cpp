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

//998244353
const int MOD = 1e9+7, N = 1e5;

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b)
{
    return mul(a,binpow(b,MOD-2));
}

int sub(int a, int b)
{
    return add(a,MOD-b);
}

int calc(int n, int mn)
{
    //cout<<n<<" "<<mn<<"\n";
    if (n<=1)
        return 1;
    int dp[n][2];
    dp[0][0]=N-mn;
    dp[0][1]=1;
    for (int i=1;i<n;++i)
    {
        dp[i][0]=mul(dp[i-1][1], N-mn);
        dp[i][1]=add(dp[i-1][0],dp[i-1][1]);
    }
    return add(dp[n-1][0],dp[n-1][1]);
}

int B[N+1];

void solve()
{
    int n,ans=1,x=1;
    cin>>n;
    for (int i=1;i<n;++i)
        cin>>B[i];
    for (int i=2;i+1<n;++i)
        if (min(B[i-1],B[i+1])>B[i])
        {
            cout<<"0\n";
            return;
        }
    for (int i=2;i<n;++i)
    {
        if (B[i-1]<B[i])
        {
            ans=mul(ans,calc(i-x,B[i-1]));
            x=i;
        }
        else if (B[i-1]>B[i])
        {
            ans=mul(ans,calc(i-x+1,B[i-1]));
            x=i+1;
        }
    }
    cout<<mul(ans,calc(n-x+1,B[n-1]))<<"\n";
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