#include <bits/stdc++.h>
using namespace std;

struct disjoint_set_union {
    vector<int> p, sz;
    vector<bool> cyc;
    disjoint_set_union(int n) : p(n + 1), sz(n + 1, 1), cyc(n + 1) {
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

struct strongly_connected_components {
    int n, component_count;
    vector<vector<int>> edges, reverse_edges;
    vector<int> component, component_size;
    strongly_connected_components(int n) : n(n), edges(n + 1), reverse_edges(n + 1), component(n + 1), component_size(n + 1), component_count(0) {}
    void add_edge(int x, int y) {
        edges[x].push_back(y);
        reverse_edges[y].push_back(x);
    }
    void dfs(int c, vector<int>& out_order, vector<bool>& done) {
        done[c] = true;
        for (int i : edges[c])
            if (!done[i])
                dfs(i, out_order, done);
        out_order.push_back(c);
    }
    void dfs_reverse(int c, vector<bool>& done) {
        done[c] = true;
        component[c] = component_count;
        ++component_size[component_count];
        for (int i : reverse_edges[c])
            if (!done[i])
                dfs_reverse(i, done);
    }
    void build_scc() {
        vector<int> out_order;
        vector<bool> done(n + 1, false), done_reverse(n + 1, false);
        for (int i = 1; i <= n; ++i)
            if (!done[i])
                dfs(i, out_order, done);
        component_count = 0;
        for (int i = out_order.size() - 1; i >= 0; --i)
            if (!done_reverse[out_order[i]]) {
                ++component_count;
                component_size[component_count] = 0;
                dfs_reverse(out_order[i], done_reverse);
            }
    }
    int size_of_component(int x) {
        return component_size[component[x]];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> e(n + 1);
    disjoint_set_union dsu(n);
    strongly_connected_components scc(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        dsu.unite(x, y);
        scc.add_edge(x, y);
    }
    scc.build_scc();
    vector<bool> has_cycle(n);
    for (int i = 1; i <= n; ++i)
        if (scc.size_of_component(i) > 1)
            has_cycle[dsu.find_set(i)] = true;
    for (int i = 1; i <= n; ++i)
        if (dsu.find_set(i) == i) {
            if (has_cycle[i])
                ans += dsu.sz[i];
            else
                ans += dsu.sz[i] - 1;
        }
    cout << ans;
    return 0;
}