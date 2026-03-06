#include <bits/stdc++.h>
using namespace std;

struct tree {
    int n, l, timer = 0;
    vector<int> tin, tout, height, val;
    vector<vector<int>> up, e, mini;
    tree(int n) : n(n), l((int)log2(n + 1) + 1), e(n + 1), tin(n + 1), tout(n + 1), height(n + 1), val(n + 1, n), up((int)log2(n + 1) + 1, vector<int>(n + 1)), mini((int)log2(n + 1) + 1, vector<int>(n + 1)) {}
    void add_directed_edge(int x, int y) {
        e[x].push_back(y);
    }
    void add_undirected_edge(int x, int y) {
        e[x].push_back(y);
        e[y].push_back(x);
    }
    void build_lca(int c, int p) {
        up[0][c] = p;
        mini[0][c] = val[p];
        height[c] = height[p] + 1;
        for (int i = 1; i < l; ++i) {
            up[i][c] = up[i - 1][up[i - 1][c]];
            mini[i][c] = min(mini[i - 1][c], mini[i - 1][up[i - 1][c]]);
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
    int query_ans(int x, int y) {
        int z = lca(x, y), cur_min = min(val[x], val[y]), xx = x, yy = y;
        for (int i = l; i >= 0; --i) {
            if ((height[x] - height[z]) & (1 << i)) {
                cur_min = min(cur_min, mini[i][xx]);
                xx = up[i][xx];
            }
            if ((height[y] - height[z]) & (1 << i)) {
                cur_min = min(cur_min, mini[i][yy]);
                yy = up[i][yy];
            }
        }
        return height[x] + height[y] - height[z] * 2 + cur_min * 2;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, t, x, y;
    cin >> n >> t;
    vector<vector<int>> e(n + 1);
    tree tt(n);
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (x == 1) {
            tt.val[i] = 0;
            q.push(i);
        }
    }
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
        tt.add_undirected_edge(x, y);
    }
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i : e[x]) {
            if (tt.val[i] == n) {
                tt.val[i] = tt.val[x] + 1;
                q.push(i);
            }
        }
    }
    tt.build_queries();
    while (t--) {
        cin >> x >> y;
        cout << tt.query_ans(x, y) << "\n";
    }
    return 0;
}