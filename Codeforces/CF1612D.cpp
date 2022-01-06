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

ll x;
set<array<ll,2>> s;
bool ok;

array<ll,2> fix(ll a, ll b)
{
    return {max(a,b),min(a,b)};
}

void dfs(array<ll,2> a)
{
    s.insert(a);
    cout<<a[0]<<" "<<a[1]<<"\n";
    if (a[0]==1)
    {
        if (a[1]<x)
            return;
        ok=1;
    }
    if (a[1]==1)
    {
        if (a[0]<x)
            return;
        ok=1;
    }
    if (a[0]==x||a[1]==x)
        ok=1;
    if (ok)
        return;
    if (!s.count(fix(a[0]-a[1],a[1])))
        dfs(fix(a[0]-a[1],a[1]));
    if (!s.count(fix(a[0],a[0]-a[1])))
        dfs(fix(a[0],a[0]-a[1]));
}

void solve() {
    ll a,b;
    cin>>a>>b>>x;
    ok=0;
    s.clear();
    dfs(fix(a,b));
    if (ok)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}