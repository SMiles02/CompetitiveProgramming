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
            if (sz[i] < sz[j]) {
                swap(i, j);
            }
            p[j] = i;
            sz[i] += sz[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, l = 0, r;
    cin >> n >> m;
    disjoint_set_union dsu(n);
    vector<array<int, 4>> e(m);
    vector<bool> ans(m);
    for (int i = 0; i < m; ++i) {
        cin >> e[i][1] >> e[i][2] >> e[i][0];
        e[i][3] = i;
    }
    sort(e.begin(), e.end());
    while (l < m) {
        r = l;
        while (r + 1 != m && e[r + 1][0] == e[l][0]) {
            ++r;
        }
        for (int i = l; i <= r; ++i) {
            ans[e[i][3]] = !dsu.connected(e[i][1], e[i][2]);
        }
        for (int i = l; i <= r; ++i) {
            dsu.unite(e[i][1], e[i][2]);
        }
        l = r + 1;
    }
    for (auto tf : ans) {
        if (tf) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}