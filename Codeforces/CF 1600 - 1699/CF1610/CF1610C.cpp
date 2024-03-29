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

int n, a[200000][2];

bool ok(int x)
{
    int cur=0;
    for (int i=0;i<n&&cur<x;++i)
        if (a[i][1]>=cur&&a[i][0]>=x-cur-1)
            ++cur;
    return cur == x;
}

void solve() {
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i][0]>>a[i][1];
    int l=0,r=n,m;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (ok(m))
            l=m;
        else
            r=m-1;
    }
    cout<<l<<"\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}