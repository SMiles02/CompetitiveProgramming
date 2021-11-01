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

const int N = 5005, K = 1e6+3, INF = 1e9;
int l[K];
ll p[N];

void solve()
{
    int n,k,ans=INF;
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>p[i];
        p[i]+=p[i-1];
    }
    for (int i=0;i<=k;++i)
        l[i]=INF;
    for (int i=2;i<=n;++i)
    {
        for (int j=i-1;j>0&&p[i-1]-p[j-1]<=k;--j)
            l[p[i-1]-p[j-1]]=min(l[p[i-1]-p[j-1]],i-j);
        for (int j=i;j<=n&&p[j]-p[i-1]<=k;++j)
            ans=min(ans,j-i+1+l[k-p[j]+p[i-1]]);
    }
    for (int i=1;i<=n;++i)
        l[p[n]-p[i-1]]=min(l[p[n]-p[i-1]],n-i+1);
    ans=min(ans,l[k]);
    if (ans==INF)
        ans=-1;
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for (int i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}