#include <bits/stdc++.h>
using namespace std;

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
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

void solve() {
    int n, m, par = 0;
    cin >> n >> m;
    vector<int> v(n + 1), t(n + 1);
    disjoint_set_union dsu(n * 2);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        par += v[i] & 1;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
        par += t[i] & 1;
    }
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        dsu.unite(x, y + n);
        dsu.unite(x + n, y);
    }
    if (par & 1) {
        cout << "NO\n";
        return;
    }
    if (dsu.connected(1, n + 1)) {
        cout << "YES\n";
        return;
    }
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (dsu.connected(i, 1)) {
            sum += v[i] - t[i];
        }
        else {
            sum -= v[i] - t[i];
        }
    }
    if (sum == 0) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}