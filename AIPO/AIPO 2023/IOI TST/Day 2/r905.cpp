#include <bits/stdc++.h>
using namespace std;

struct disjoint_set_union {
    vector<int> p, sz;
    disjoint_set_union(int n) : p(n), sz(n, 1) {
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, u;
    long long ans = 0;
    cin >> n >> m >> u;
    vector<bool> marked(n), done(n);
    while (u--) {
        int k;
        cin >> k;
        marked[k] = true;
    }
    vector<array<int, 3>> edges(m);
    for (auto &[w, x, y] : edges) {
        cin >> x >> y >> w;
    }
    sort(edges.begin(), edges.end());
    if (n == 2) {
        cout << edges[0][0];
        return 0;
    }
    disjoint_set_union dsu(n);
    for (auto &[w, x, y] : edges) {
        if ((marked[x] ^ marked[y]) && !done[x] && !done[y]) {
            dsu.unite(x, y);
            ans += w;
            done[x] = marked[x];
            done[y] = marked[y];
        }
    }
    for (auto &[w, x, y] : edges) {
        if (!marked[x] && !marked[y] && !dsu.connected(x, y)) {
            dsu.unite(x, y);
            ans += w;
        }
    }
    if (dsu.sz[dsu.find_set(0)] == n)
        cout << ans;
    else
        cout << "NOPE!";
    return 0;
}