#include <bits/stdc++.h>
using namespace std;

struct disjoint_set_union {
    int cmp;
    vector<int> p, sz;
    disjoint_set_union(int n) : p(n + 1), sz(n + 1, 1), cmp(n) {
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
            --cmp;
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    set<array<int, 2>> edges;
    disjoint_set_union dsu(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        edges.insert({min(x, y), max(x, y)});
    }
    int a[k][2], ans[k];
    for (int i = 0; i < k; ++i) {
        cin >> a[i][0] >> a[i][1];
        edges.erase({min(a[i][0], a[i][1]), max(a[i][0], a[i][1])});
    }
    for (auto i : edges)
        dsu.unite(i[0], i[1]);
    for (int i = k - 1; i >= 0; --i) {
        ans[i] = dsu.cmp;
        dsu.unite(a[i][0], a[i][1]);
    }
    for (int i = 0; i < k; ++i)
        cout << ans[i] << " ";
    return 0;
}