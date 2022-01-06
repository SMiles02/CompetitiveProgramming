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

int n, a[200001];
ll s, k;

bool check(ll x) {
    if (s-x <= k)
        return 1;
    ll cur = s - a[0];
    for (int i=1;i<min(1LL*n,x);++i)
    {
        cur-=a[n-i];
        if (cur+1LL*(a[0]-x+i)*(i+1)<=k)
            return 1;
    }
    return 0;
}

void solve() {
    ll l=0,r,m,a2=1e18,tmp;
    s=0;
    cin>>n>>k;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
    tmp=s;
    sort(a,a+n);
    for (int i=1;i<=n;++i)
    {
        tmp-=a[n-i];
        tmp+=a[0];
        if (tmp<=k)
            a2=min(a2,1LL*i);
    }
    r=1;
    while (!check(r))
        r*=2;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (check(m))
            r=m;
        else
            l=m+1;
    }
    cout<<min(l,a2)<<"\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}