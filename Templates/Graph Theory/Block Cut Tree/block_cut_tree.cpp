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