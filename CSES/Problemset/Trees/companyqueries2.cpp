#include <bits/stdc++.h>
using namespace std;

struct LCA {
    int N, L, timer = 0;
    vector<int> tin, tout;
    vector<vector<int>> up, e;
    LCA(int n) : N(n), L((int)log2(n + 1) + 1), e(n + 1), tin(n + 1), tout(n + 1), up((int)log2(n + 1) + 1, vector<int>(n + 1)) {}
    void add_directed_edge(int x, int y) {
        e[x].push_back(y);
    }
    void add_undirected_edge(int x, int y) {
        e[x].push_back(y);
        e[y].push_back(x);
    }
    void build_lca(int c, int p) {
        up[0][c] = p;
        for (int i = 1; i < L; ++i)
            up[i][c] = up[i - 1][up[i - 1][c]];
        tin[c] = ++timer;
        for (int i : e[c])
            build_lca(i, c);
        tout[c] = ++timer;
    }
    void build_lca(int root = 1) {
        build_lca(root, 0);
        tout[0] = ++timer;
    }
    bool is_ancestor(int u, int v)  {
        return (tin[u] <= tin[v] && tout[v] <= tout[u]);
    }
    int query(int u, int v)
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = L - 1; i >= 0; --i)
            if (!is_ancestor(up[i][u], v))
                u = up[i][u];
        return up[0][u];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, p, x, y;
    cin >> n >> q;
    LCA lca(n);
    for (int i = 2; i <= n; ++i) {
        cin >> p;
        lca.add_directed_edge(p, i);
    }
    lca.build_lca();
    while (q--) {
        cin >> x >> y;
        cout << lca.query(x, y) << "\n";
    }
    return 0;
}