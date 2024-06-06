#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

struct tree {
    int N, L, timer = 0;
    vector<int> tin, tout, height;
    vector<vector<int>> up, e;
    tree(int n) : N(n), L((int)log2(n + 1) + 1), e(n + 1), tin(n + 1), tout(n + 1), height(n + 1), up((int)log2(n + 1) + 1, vector<int>(n + 1)) {}
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
        tout[c] = timer;
    }
    void build_queries(int root = 1) {
        build_lca(root, 0);
        tout[0] = ++timer;
    }
    bool is_ancestor(int x, int y)  {
        return (tin[x] <= tin[y] && tout[y] <= tout[x]);
    }
    int query_kth_ancestor(int x, int k) {
        for (int i = 0; i < L; ++i)
            if (k & (1 << i))
                x = up[i][x];
        return x;
    }
    int lca(int x, int y) {
        if (is_ancestor(x, y))
            return x;
        if (is_ancestor(y, x))
            return y;
        for (int i = L - 1; i >= 0; --i)
            if (!is_ancestor(up[i][x], y))
                x = up[i][x];
        return up[0][x];
    }
    int dist(int x, int y) {
        return height[x] + height[y] - height[lca(x, y)] * 2;
    }
};

void solve() {
    int n, k;
    cin >> n;
    tree t(n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        t.add_undirected_edge(x, y);
    }
    t.build_queries();
    cin >> k;
    vector<array<int, 3>> c(k);
    vector<int> dp(1 << k, k + 1);
    for (int i = 0; i < k; ++i) {
        cin >> c[i][0] >> c[i][1];
        c[i][2] = t.lca(c[i][0], c[i][1]);
    }
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        for (int j = 0; j < k; ++j) {
            if (i != c[j][2] && t.is_ancestor(c[j][2], i) && (t.is_ancestor(i, c[j][0]) || t.is_ancestor(i, c[j][1]))) {
                cur += 1 << j;
            }
        }
        dp[cur] = 1;
    }
    for (int i = (1 << k) - 1; i > 0; --i) {
        for (int j = 0; j < k; ++j) {
            if (!(i & (1 << j))) {
                dp[i] = min(dp[i], dp[i ^ (1 << j)]);
            }
        }
    }
    for (int i = 1; i < (1 << k); ++i) {
        for (int j = ((i - 1) & i); j > 0; j = ((j - 1) & i)) {
            dp[i] = min(dp[i], dp[j] + dp[i ^ j]);
        }
    }
    cout << dp[(1 << k) - 1] << "\n";
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