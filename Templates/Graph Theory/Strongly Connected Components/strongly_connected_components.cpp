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
};