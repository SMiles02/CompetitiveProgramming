struct reachability_tree {
    int n, lg, t, timer;
    vector<int> dsu, tin, tout, time_of_creation;
    vector<bool> done;
    vector<vector<int>> e, up;
    reachability_tree(int n) : n(n), lg((int)log2(n * 2 + 1) + 2), t(n + 1), timer(0), dsu(n * 2 + 1), tin(n * 2 + 1), tout(n * 2 + 1), time_of_creation(n * 2 + 1), done(n * 2 + 1), e(n * 2 + 1), up((int)log2(n * 2 + 1) + 2, vector<int>(n * 2 + 1)) {
        for (int i = 0; i <= n; ++i) {
            dsu[i] = i;
            up[0][i] = i;
        }
    }
    int find_set(int x) {
        return x == dsu[x] ? x : dsu[x] = find_set(dsu[x]);
    }
    void unite(int x, int y, int time_of_edge = 0) {
        x = find_set(x);
        y = find_set(y);
        if (x != y) {
            up[0][x] = up[0][y] = up[0][t] = dsu[x] = dsu[y] = dsu[t] = t;
            time_of_creation[t] = time_of_edge;
            e[t].push_back(x);
            e[t].push_back(y);
            t++;
        }
    }
    void dfs(int c) {
        done[c] = true;
        tin[c] = ++timer;
        for (int i : e[c])
            dfs(i);
        tout[c] = ++timer;
    }
    void build_tree() {
        for (int i = t - 1; i >= 0; --i) {
            if (!done[i])
                dfs(i);
            for (int j = 1; j < lg; ++j)
                up[j][i] = up[j - 1][up[j - 1][i]];
        }
    }
    bool is_ancestor(int x, int y) {
        return tin[x] <= tin[y] && tout[y] <= tout[x];
    }
    int time_of_connection(int x, int y) {
        for (int i = lg - 1; i >= 0; --i)
            if (!is_ancestor(up[i][x], y))
                x = up[i][x];
        if (is_ancestor(up[0][x], y))
            return time_of_creation[up[0][x]];
        else
            return -1;
    }
};

// Notes:

// n = number of nodes

// unite(x, y, time [if non-zero])
// add edges [remember to add them in order of time]

// build_tree()
// no more edges need to be added, we can start querying after this

// time_of_connection(x, y)
// tells you when x and y initially get connected
// returns -1 if x and y are never connected