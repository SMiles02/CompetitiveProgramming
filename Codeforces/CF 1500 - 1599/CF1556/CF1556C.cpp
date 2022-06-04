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

vector<array<int,2>> v,w;
  
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    ll ans=0;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        if (i&1)
        {
            for (auto j : v)
                ans+=max(0LL,min(j[1],x)-max(1LL,j[0])+1);
            for (auto j : v)
                if (j[1]>=x)
                    w.push_back({max(0LL,j[0]-x),j[1]-x});
        }
        else
        {
            for (auto j : v)
                w.push_back({j[0]+x,j[1]+x});
            w.push_back({1LL,x});
        }
        swap(v,w);
        w.clear();
        // for (auto i : v)
        //     cout<<i[0]<<" "<<i[1]<<"\n";
        // cout<<ans<<"\n";
        // cout<<"-----\n";
    }
    cout<<ans;
    return 0;
}