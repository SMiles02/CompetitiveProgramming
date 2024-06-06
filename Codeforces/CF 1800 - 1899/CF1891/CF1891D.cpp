#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9 + 7, N = 2e5 + 1;
int f[N];

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b) { return mul(a, binpow(b, MOD - 2)); }

int sub(int a, int b) { return add(a, MOD - b); }

vector<array<ll, 3>> ranges;

void solve() {
    ll l, r;
    cin >> l >> r;
    int ans = 0;
    for (auto [xl, xr, xy] : ranges) {
        if (l <= xr && xl <= r) {
            ans = add(ans, mul(xy, add(sub(min(xr, r) % MOD, max(xl, l) % MOD), 1)));
        }
    }
    cout << ans << "\n";
}

ll safe_mul(ll a, ll b) {
    if (__lg(a) + __lg(b) < 61) {
        return 1LL * a * b;
    }
    return 1LL << 61;
}

void add_range(ll l, ll r, ll x) {
    ranges.push_back({l, r, x});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    add_range(4, 7, 2);
    for (int i = 3; i < 60; ++i) {
        // cout << i << ":\n";
        ll l = (1LL << i), r = (1LL << (i + 1)) - 1, p = 1, c = i;
        while (safe_mul(c, i) <= l) {
            c *= i;
            ++p;
        }
        add_range(l, min(r, safe_mul(c, i) - 1), p);
        while (safe_mul(c, i) <= r) {
            c = safe_mul(c, i);
            ++p;
            add_range(c, min(r, safe_mul(c, i) - 1), p);
        }
    }
    cout << ranges.size() << "\n";
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}