#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int mul(int a, int b) { return (1LL * a * b) % MOD; }

int binpow(int a, long long b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

struct disjoint_set_union {
    vector<int> p, sz;
    disjoint_set_union(int n) : p(n + 1), sz(n + 1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find_set(int i) {
        return i == p[i] ? i : p[i] = find_set(p[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            p[j] = i;
            sz[i] += sz[j];
        }
    }
    int component_size(int x) {
        return sz[find_set(x)];
    }
};

void solve() {
    int n, s, ans = 1;
    cin >> n >> s;
    vector<array<int, 3>> e(n - 1);
    disjoint_set_union dsu(n);
    for (auto &[w, x, y] : e) {
        cin >> x >> y >> w;
    }
    sort(e.begin(), e.end());
    for (auto &[w, x, y] : e) {
        ans = mul(ans, binpow(s - w + 1, 1LL * dsu.component_size(x) * dsu.component_size(y) - 1));
        dsu.unite(x, y);
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