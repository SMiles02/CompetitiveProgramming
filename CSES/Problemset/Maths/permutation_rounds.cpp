#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct disjoint_set_union {
    int n;
    vector<int> p, sz;
    disjoint_set_union(int n) : n(n), p(n + 1), sz(n + 1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find_set(int x) {
        if (p[x] == x) {
            return x;
        }
        return p[x] = find_set(p[x]);
    }
    void unite(int x, int y) {
        x = find_set(x);
        y = find_set(y);
        if (x != y) {
            if (sz[x] < sz[y]) {
                swap(x, y);
            }
            sz[x] += sz[y];
            p[y] = x;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans = 1;
    cin >> n;
    vector<int> lcm_pow(n + 1);
    disjoint_set_union dsu(n);
    for (int i = 1, pi; i <= n; ++i) {
        cin >> pi;
        dsu.unite(i, pi);
    }
    for (int i = 1; i <= n; ++i) {
        if (i == dsu.find_set(i)) {
            int k = dsu.sz[i];
            for (int j = 2; j * j <= k; ++j) {
                if (k % j == 0) {
                    int cur = 0;
                    while (k % j == 0) {
                        k /= j;
                        ++cur;
                    }
                    lcm_pow[j] = max(lcm_pow[j], cur);
                }
            }
            if (k > 1) {
                lcm_pow[k] = max(lcm_pow[k], 1);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < lcm_pow[i]; ++j) {
            ans = (1LL * ans * i) % MOD;
        }
    }
    cout << ans;
    return 0;
}