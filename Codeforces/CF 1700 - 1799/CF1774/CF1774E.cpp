#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int N, L, timer = 0;
    vector<int> tin, tout, height;
    vector<vector<int>> up, e;
    Tree(int n) : N(n), L((int)log2(n + 1) + 1), e(n + 1), tin(n + 1), tout(n + 1), height(n + 1), up((int)log2(n + 1) + 1, vector<int>(n + 1)) {}
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
        for (int i = 1; i < L; ++i)
            up[i][c] = up[i - 1][up[i - 1][c]];
        tin[c] = ++timer;
        for (int i : e[c])
            if (i != p)
                build_lca(i, c);
        tout[c] = ++timer;
    }
    void build_queries(int root = 1) {
        build_lca(root, 0);
        tout[0] = ++timer;
    }
    bool is_ancestor(int u, int v)  {
        return (tin[u] <= tin[v] && tout[v] <= tout[u]);
    }
    int query_kth_ancestor(int x, int k) {
        for (int i = 0; i < L; ++i)
            if (k & (1 << i))
                x = up[i][x];
        return x;
    }
    int lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = L - 1; i >= 0; --i)
            if (!is_ancestor(up[i][u], v))
                u = up[i][u];
        return up[0][u];
    }
    int query_distance(int u, int v) {
        return height[u] + height[v] - height[lca(u, v)] * 2;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, d, x, y, k;
    cin >> n >> d;
    Tree tree(n);
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        tree.add_undirected_edge(x, y);
    }
    tree.build_queries();
    vector<array<int, 2>> a, b;
    cin >> k;
    while (k--) {
        cin >> x;
        a.push_back({tree.tin[x], x});
        y = tree.query_kth_ancestor(x, d);
        if (y != 0)
            b.push_back({tree.tin[y], y});
    }
    cin >> k;
    while (k--) {
        cin >> x;
        b.push_back({tree.tin[x], x});
        y = tree.query_kth_ancestor(x, d);
        if (y != 0)
            a.push_back({tree.tin[y], y});
    }
    a.push_back({tree.tin[1], 1});
    b.push_back({tree.tin[1], 1});
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans = 0;
    for (int i = 1; i < a.size(); ++i)
        ans += tree.query_distance(a[i - 1][1], a[i][1]);
    for (int i = 1; i < b.size(); ++i)
        ans += tree.query_distance(b[i - 1][1], b[i][1]);
    ans += tree.query_distance(a[0][1], a[a.size() - 1][1]);
    ans += tree.query_distance(b[0][1], b[b.size() - 1][1]);
    cout << ans;
    return 0;
}