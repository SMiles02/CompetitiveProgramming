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

void solve()
{
    int n,k,inc=0;
    ll ans=0;
    cin>>n>>k;
    int a[n],t[n];
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ans+=a[i];
        t[i]=k;
        if (a[i]>0)
            t[i]=0;
    }
    for (int i=1;i<n;++i)
        t[i]=min(t[i-1]+1,t[i]);
    t[0]=min(t[n-1]+1,t[0]);
    for (int i=1;i<n;++i)
        t[i]=min(t[i-1]+1,t[i]);
    for (int i=n-2;i>=0;--i)
        t[i]=min(t[i+1]+1,t[i]);
    t[n-1]=min(t[0]+1,t[n-1]);
    for (int i=n-2;i>=0;--i)
        t[i]=min(t[i+1]+1,t[i]);
    for (int i=0;i<n;++i)
        ans+=(k-t[i])*2;
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