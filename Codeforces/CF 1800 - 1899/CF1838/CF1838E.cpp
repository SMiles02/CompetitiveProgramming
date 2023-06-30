#include <bits/stdc++.h>
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

int C(int n, int k) { return dv(f[n], mul(f[k], f[n - k])); }

void calc_factorials() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = mul(f[i - 1], i);
}

void solve() {
    int n, m, k, ai, mCi = 1, ans;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> ai;
    ans = binpow(k, m);
    for (int i = 0; i < n; ++i) {
        ans = sub(ans, mul(dv(mCi, f[i]), binpow(k - 1, m - i)));
        mCi = mul(mCi, m - i);
    }
    cout << ans << "\n";
}

int main() {
    calc_factorials();
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}