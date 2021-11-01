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

const int M = 513;
bitset<M> dp;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=1;i<(1<<n);++i)
    {
        std::vector<int> v;
        for (int j=0;j<n;++j)
            if ((1<<j)&i)
                v.push_back(a[j]);
        bool ok=1;
        for (int j=1;j<sz(v);++j)
            if (v[j-1]>v[j])
                ok=0;
        if (ok)
        {
            x=0;
            for (int j : v)
                x^=j;
            dp[x]=1;
        }
    }
    dp[0]=1;
    cout<<dp.count()<<"\n";
    for (int i=0;i<M;++i)
        if (dp[i])
            cout<<i<<" ";
    return 0;
}