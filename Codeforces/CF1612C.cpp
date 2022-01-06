// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a) {
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

ll f(ll x)
{
    return (x*(x+1))/2;
}

void solve() {
    ll k,x;
    cin>>k>>x;
    ll l=1,r=k*2-1,m;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (m<=k)
        {
            if (f(m)<x)
                l=m+1;
            else
                r=m;
        }
        else
        {
            if (f(k)+f(k-1)-f(k*2-1-m)<x)
                l=m+1;
            else
                r=m;
        }
    }
    cout<<l<<"\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}