//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
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

ll f(ll x)
{
    return (x*(x+1))/2;
}

ll f(ll x, ll y)
{
    return f(y)-f(x);
}
  
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,cur,ct=1,x;
    ll ans=0;
    cin>>n>>k;
    vector<int> v={0};
    for (int i=0;i<n;++i)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    cur=v.back();
    v.pop_back();
    while (!v.empty()&&k)
    {
        if (1LL*ct*(cur-v.back())>k)
        {
            x=k/ct;
            k-=x*ct;
            //cout<<ct<<" "<<f(cur-x,cur)<<"\n";
            ans+=1LL*ct*f(cur-x,cur);
            //cout<<ans<<"\n";
            cur-=x;
            ans+=cur*k;
            k=0;
        }
        else
        {
            k-=ct*(cur-v.back());
            ans+=1LL*ct*f(v.back(),cur);
            cur=v.back();
            ++ct;
        }
        v.pop_back();
    }
    cout<<ans;
    return 0;
}