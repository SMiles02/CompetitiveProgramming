#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353, N = 6e5 + 1;
int f[N], count_seq[N];

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

int C(int n, int k) { return dv(f[n], mul(f[k], f[n - k])); }

void calc_factorials() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = mul(f[i - 1], i);
}

int ans;
set<array<int, 2>> s;
bool odd;

void solve_range() {
    if (s.empty())
        return;
    auto [l, r] = *s.begin();
    s.erase(s.begin());
    vector<array<int, 2>> v;
    while (!s.empty()) {
        auto [x, y] = *s.begin();
        if (y > r)
            break;
        v.push_back({x, y});
        s.erase(s.begin());
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    s.insert({1, n});
    while (k--) {
        int l, r;
        cin >> l >> r;
        s.insert({l, r});
    }
    odd = false;
    ans = 1;
    solve_range();
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    for (int i = 2; i < N; i += 2) {
        count_seq[i] = dv(C(i, i / 2), i / 2 + 1);
        // cout << i << ": " << count_seq[i] << "\n";
    }
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}