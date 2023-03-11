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

struct DSU {
    vector<int> pt, rk, self_cyc, cyc;
    DSU(int n) : pt(n + 1), rk(n + 1, 1), self_cyc(n + 1), cyc(n + 1) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
            cyc[i] += cyc[j];
            self_cyc[i] += self_cyc[j];
        }
        else
            ++cyc[i];
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

void solve() {
    int n, ans = 1;
    cin >> n;
    int a[n], b[n];
    DSU dsu(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i])
            ++dsu.self_cyc[dsu.find_set(a[i])];
        else
            dsu.unite(a[i], b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (dsu.cyc[dsu.find_set(i)] + dsu.self_cyc[dsu.find_set(i)] == 0)
            ans = 0;
        if (i == dsu.find_set(i)) {
            if (dsu.self_cyc[dsu.find_set(i)])
                ans = mul(ans, n);
            else
                ans = mul(ans, 2);
        }
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