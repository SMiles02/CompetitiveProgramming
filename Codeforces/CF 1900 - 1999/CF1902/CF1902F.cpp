#include <bits/stdc++.h>
using namespace std;

struct xor_basis {
    int n, sz;
    vector<int> basis;
    xor_basis(int n) : n(n), sz(0) {}
    void add_vector(int mask) {
        for (auto &i : basis) {
            mask = min(mask, mask ^ i);
        }
        if (mask) {
            basis.push_back(mask);
            ++sz;
        }
    }
    bool check_possible(int mask) {
        for (auto &i : basis) {
            mask = min(mask, mask ^ i);
        }
        return mask == 0;
    }
    void merge(xor_basis basis_2) {
        for (int mask : basis_2.basis) {
            add_vector(mask);
        }
    }
};

struct tree {
    int n, l, timer = 0;
    vector<int> tin, tout, height, a;
    vector<vector<int>> up, e;
    vector<vector<xor_basis>> basis;
    tree(int n) : n(n), l((int)log2(n + 1) + 1), e(n + 1), tin(n + 1), tout(n + 1), height(n + 1), a(n + 1), up((int)log2(n + 1) + 1, vector<int>(n + 1)), basis((int)log2(n + 1) + 1, vector<xor_basis>(n + 1, 20)) {}
    void add_directed_edge(int x, int y) {
        e[x].push_back(y);
    }
    void add_undirected_edge(int x, int y) {
        e[x].push_back(y);
        e[y].push_back(x);
    }
    void build_lca(int c, int p) {
        up[0][c] = p;
        height[c] = height[p] + 1;
        basis[0][c].add_vector(a[c]);
        for (int i = 1; i < l; ++i) {
            up[i][c] = up[i - 1][up[i - 1][c]];
            basis[i][c] = basis[i - 1][c];
            basis[i][c].merge(basis[i - 1][up[i - 1][c]]);
        }
        tin[c] = ++timer;
        for (int i : e[c]) {
            if (i != p) {
                build_lca(i, c);
            }
        }
        tout[c] = timer;
    }
    void build_queries(int root = 1) {
        build_lca(root, 0);
        tout[0] = ++timer;
    }
    bool is_ancestor(int x, int y)  {
        return tin[x] <= tin[y] && tout[y] <= tout[x];
    }
    int query_kth_ancestor(int x, int k) {
        for (int i = 0; i < l; ++i) {
            if (k & (1 << i)) {
                x = up[i][x];
            }
        }
        return x;
    }
    int lca(int x, int y) {
        if (is_ancestor(x, y)) {
            return x;
        }
        if (is_ancestor(y, x)) {
            return y;
        }
        for (int i = l - 1; i >= 0; --i) {
            if (!is_ancestor(up[i][x], y)) {
                x = up[i][x];
            }
        }
        return up[0][x];
    }
    int query_distance(int x, int y) {
        return height[x] + height[y] - height[lca(x, y)] * 2;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n;
    tree t(n);
    for (int i = 1, ai; i <= n; ++i) {
        cin >> ai;
        t.a[i] = ai;
    }
    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        t.add_undirected_edge(x, y);
    }
    t.build_queries();
    cin >> q;
    while (q--) {
        int x, y, k, l, d;
        cin >> x >> y >> k;
        xor_basis basis(20);
        l = t.lca(x, y);
        d = t.height[x] - t.height[l];
        for (int i = 0; i < 20; ++i) {
            if ((1 << i) & d) {
                basis.merge(t.basis[i][x]);
                x = t.up[i][x];
            }
        }
        d = t.height[y] - t.height[l];
        for (int i = 0; i < 20; ++i) {
            if ((1 << i) & d) {
                basis.merge(t.basis[i][y]);
                y = t.up[i][y];
            }
        }
        basis.add_vector(t.a[l]);
        if (basis.check_possible(k)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}