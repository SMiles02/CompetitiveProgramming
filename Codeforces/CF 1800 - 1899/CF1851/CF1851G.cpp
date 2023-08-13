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

int midpoint(int l, int r) {
    return l + (r - l) / 2;
}

void solve() {
    int n, m, q, cnt = 0;
    cin >> n >> m;
    vector<int> h(n + 1), v;
    vector<array<int, 3>> edges(m + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        edges[i] = {max(h[x], h[y]), x, y};
    }
    edges[m] = {0, 1, 1};
    sort(edges.begin(), edges.end());
    cin >> q;
    vector<array<int, 3>> queries(q);
    vector<int> ans(q, m + 1);
    vector<vector<array<int, 5>>> pbs(m + 1);
    for (auto& [x, y, e] : queries) {
        cin >> x >> y >> e;
        pbs[midpoint(0, m)].push_back({0, m, x, y, cnt++});
    }
    for (int _ = 0; _ < 19; ++_) {
        disjoint_set_union dsu(n);
        for (int i = 0; i <= m; ++i) {
            dsu.unite(edges[i][1], edges[i][2]);
            for (auto& [l, r, x, y, id] : pbs[i]) {
                int newl, newr;
                if (dsu.connected(x, y)) {
                    ans[id] = i;
                    newl = l;
                    newr = i - 1;
                }
                else {
                    newl = i + 1;
                    newr = r;
                }
                if (newl <= newr) {
                    pbs[midpoint(newl, newr)].push_back({newl, newr, x, y, id});
                }
            }
            pbs[i].clear();
        }
    }
    for (int i = 0; i < q; ++i) {
        if (ans[i] <= m && edges[ans[i]][0] - h[queries[i][0]] <= queries[i][2]) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}