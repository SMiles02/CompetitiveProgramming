#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353, N = 2e5 + 1;
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

struct BIT {
    int n, rtn;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1) {}
    void update(int x, int d) {
        for (int i = x; i <= n; i += i & -i) {
            bit[i] = add(bit[i], d);
        }
    }
    int query(int x) {
        rtn = 0;
        for (int i = x; i; i -= i & -i) {
            rtn = add(rtn, bit[i]);
        }
        return rtn;
    }
    int query(int x, int y) {
        return sub(query(y), query(x - 1));
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    calc_factorials();
    int n, m, ans = 0, den = 1;
    cin >> n >> m;
    vector<int> v(N), t(m);
    BIT bit(N);
    for (int i = 0, k; i < n; ++i) {
        cin >> k;
        ++v[k];
    }
    for (int i = 1; i < N; ++i) {
        den = mul(den, f[v[i]]);
        bit.update(i, v[i]);
    }
    for (int i = 0; i < m; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i == m) {
            break;
        }
        // cout << i << ": (" << f[n - i - 1] << " / " << den << ") * " << bit.query(t[i] - 1) << "\n";
        // cout << "=> " << mul(dv(f[n - i - 1], den), bit.query(t[i] - 1)) << "\n";
        ans = add(ans, mul(dv(f[n - i - 1], den), bit.query(t[i] - 1)));
        if (v[t[i]] == 0) {
            break;
        }
        bit.update(t[i], MOD - 1);
        // cerr << i << " " << bit.query(t[i], t[i]) << "\n";
        den = dv(den, v[t[i]]);
        --v[t[i]];
        if (i + 1 == n && n < m) {
            ans = add(ans, 1);
        }
    }
    cout << ans;
    return 0;
}