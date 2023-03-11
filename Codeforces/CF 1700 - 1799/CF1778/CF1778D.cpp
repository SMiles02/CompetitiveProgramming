#include <bits/stdc++.h>
using namespace std;

// 998244353
const int MOD = 998244353, N = 1e6 + 1;
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
    int n, x = 0, last = 0, c, d;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    if (s == t) {
        cout << "0\n";
        return;
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }
    for (int i = 0; i < n; ++i)
        if (s[i] == t[i])
            ++x;
    vector<int> frac(n + 1), ans(n + 1);
    frac[1] = dv(1, n);
    for (int i = 2; i <= n; ++i)
        frac[i] = add(frac[i - 1], frac[1]);
    c = 1;
    d = frac[n - 1];
    vector<array<int, 2>> eq(n + 1);
    for (int i = n - 2; i > 0; --i) {
        int p = 1, q = frac[i];
        c = mul(c, frac[n - i]);
        d = mul(d, frac[n - i]);
        d = sub(1, d);
        p = add(p, c);
        p = dv(p, d);
        q = dv(q, d);
        swap(c, p);
        swap(d, q);
        eq[i] = {c, d};
    }
    ans[0] = dv(add(c, 1), sub(1, d));
    ans[1] = sub(ans[0], 1);
    for (int i = 2; i < n - 1; ++i)
        ans[i] = add(mul(ans[i - 1], eq[i][1]), eq[i][0]);
    ans[n - 1] = add(mul(frac[n - 1], ans[n - 2]), 1);
    cout << ans[x] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}