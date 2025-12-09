#include <bits/stdc++.h>
using namespace std;

struct block_cut_tree {
    int n, edge_id, bct_node_cnt;
    vector<vector<array<int, 2>>> edges;
    vector<vector<int>> edges_bct;
    vector<bool> is_split;
    block_cut_tree(int n) : n(n), edges(n + 1), edges_bct(n * 3 + 1), edge_id(0) {}
    void add_edge(int x, int y) {
        edges[x].push_back({y, edge_id});
        edges[y].push_back({x, edge_id});
        ++edge_id;
        is_split.push_back(false);
    }
    void dfs_split(int c, int pid, int& timer, vector<int>& tin, vector<int>& low, vector<bool>& done) {
        done[c] = true;
        tin[c] = low[c] = ++timer;
        for (auto i : edges[c])
            if (i[1] != pid) {
                if (done[i[0]])
                    low[c] = min(low[c], tin[i[0]]);
                else {
                    dfs_split(i[0], i[1], timer, tin, low, done);
                    low[c] = min(low[c], low[i[0]]);
                    is_split[i[1]] = tin[c] <= low[i[0]];
                }
            }
    }
    void dfs_build_bct(int c, int g, int& timer, vector<bool>& done) {
        done[c] = true;
        edges_bct[c].push_back(g + n);
        edges_bct[g + n].push_back(c);
        for (auto i : edges[c])
            if (!done[i[0]]) {
                if (is_split[i[1]]) {
                    ++timer;
                    edges_bct[c].push_back(timer + n);
                    edges_bct[timer + n].push_back(c);
                    dfs_build_bct(i[0], timer, timer, done);
                }
                else
                    dfs_build_bct(i[0], g, timer, done);
            }
    }
    void build_bct() {
        int timer = 0;
        vector<int> tin(n + 1), low(n + 1);
        vector<bool> done_dfs(n + 1), done_build(n + 1);
        bct_node_cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (!done_dfs[i]) {
                dfs_split(i, -1, timer, tin, low, done_dfs);
                ++bct_node_cnt;
                dfs_build_bct(i, bct_node_cnt, bct_node_cnt, done_build);
            }
    }
};

struct tree {
    int N, L, timer = 0;
    vector<int> tin, tout, height;
    vector<vector<int>> up, e;
    tree(int n) : N(n), L((int)log2(n + 1) + 1), e(n + 1), tin(n + 1), tout(n + 1), height(n + 1), up((int)log2(n + 1) + 1, vector<int>(n + 1)) {}
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
    int query_distance(int x, int y) {
        return height[x] + height[y] - height[lca(x, y)] * 2;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    block_cut_tree bct(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        bct.add_edge(x, y);
    }
    bct.build_bct();
    tree solve(n + bct.bct_node_cnt);
    for (int i = 1; i <= n + bct.bct_node_cnt; ++i)
        for (int j : bct.edges_bct[i])
            if (i < j)
                solve.add_undirected_edge(i, j);
    solve.build_queries();
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (solve.query_distance(x, y) == solve.query_distance(x, z) + solve.query_distance(y, z))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}