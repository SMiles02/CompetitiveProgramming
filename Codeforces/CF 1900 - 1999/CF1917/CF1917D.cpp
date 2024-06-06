#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 998244353;

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

struct BIT {
    int n, rtn; // rtn might need to be LLed
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1,0) {}
    void update(int x, int d) { for (int i = x; i <= n; i += i & -i) bit[i] += d; }
    int query(int x) {
        rtn = 0;
        for (int i = x; i; i -= i & -i) rtn += bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) - query(x - 1); }
};

void solve() {
    int n, k, ans, q_inv = 0;
    cin >> n >> k;
    vector<int> p(n), q(k), w(k), s(k + 1);
    BIT q_bit(k), bit(n * 2);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> q[i];
        q_inv = add(q_inv, q_bit.query(q[i] + 1, k));
        q_bit.update(q[i] + 1, 1);
        w[i] = k - i;
    }
    for (int i = k - 1; i >= 0; --i) {
        s[i] = add(s[i + 1], w[i]);
    }
    ans = mul(q_inv, n);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 1; j < min(k, 21); ++j) {
            int l = 0, r = n * 2 - 1, m;
            while (l < r) {
                m = l + (r - l) / 2 + 1;
                if (p[i] > (1LL << j) * m) {
                    l = m;
                }
                else {
                    r = m - 1;
                }
            }
            ans = add(ans, mul(w[j], bit.query(m)));
        }
        for (int j = 0; j < min(k, 21); ++j) {
            int l = p[i] - 1, r = n * 2, m;
            while (l < r) {
                m = l + (r - l) / 2 + 1;
                if ((1LL << j) * p[i] > m) {
                    l = m;
                }
                else {
                    r = m - 1;
                }
            }
            ans = add(ans, mul(w[j], bit.query(m)));
        }
        if (k >= 21) {
            ans = add(ans, mul(s[21], n - 1 - i));
        }
        bit.update(p[i], 1);
        // cout << ans << "\n";
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}