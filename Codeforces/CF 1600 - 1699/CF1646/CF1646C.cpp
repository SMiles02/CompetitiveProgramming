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

ll f[15];

void solve() {
    ll n, cur = 0;
    cin >> n;
    int ans = __builtin_popcountll(n);
    for (int i = 0; i < (1 << 12); ++i) {
        cur = 0;
        for (int j = 0; j < 12; ++j)
            if (i & (1 << j))
                cur += f[j + 3];
        if (cur == n)
            ans = min(ans, __builtin_popcount(i));
        else if (cur < n)
            ans = min(ans, __builtin_popcount(i) + __builtin_popcountll(n - cur));
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[1] = 1;
    for (int i = 2; i < 15; ++i)
        f[i] = f[i - 1] * i;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}