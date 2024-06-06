struct euler_path {
    int n;
    vector<vector<bool>> edge;
    euler_path(int n) : n(n), edge(n + 1, vector<bool>(n + 1)) {}
    void add_edge(int x, int y) {
        edge[x][y] = edge[y][x] = true;
    }
    void cycle(deque<int>& d) {
        d.push_front(d.back());
        d.pop_back();
    }
    int is_solvable() {
        // assumes all edges are part of a single component
        int odd_deg = 0;
        vector<int> deg(n + 1);
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i != j) {
                    deg[i] += edge[i][j];
                }
            }
            odd_deg += deg[i] & 1;
        }
        if (odd_deg != 0 && odd_deg != 2) {
            return -1;
        }
        for (int i = 0; i <= n; ++i) {
            if (deg[i] & 1) {
                return i;
            }
        }
        for (int i = 0; i <= n; ++i) {
            if (deg[i] > 0) {
                return i;
            }
        }
        return 0;
    }
    deque<int> find_path(int src = 1) {
        int not_done = 0;
        deque<int> d = {-1, src};
        vector<int> s(n + 1);
        vector<vector<bool>> e = edge;
        for (int i = 0; i <= n; ++i) {
            bool has_edges = false;
            for (int j = 0; j <= n; ++j) {
                has_edges |= e[i][j];
            }
            not_done += has_edges;
        }
        while (not_done > 0) {
            int x = d.back();
            if (x == -1) {
                cycle(d);
            }
            while (s[x] <= n && !e[x][s[x]]) {
                ++s[x];
                if (s[x] > n) {
                    --not_done;
                }
            }
            if (s[x] > n) {
                cycle(d);
            }
            else {
                e[x][s[x]] = e[s[x]][x] = false;
                d.push_back(s[x]);
            }
        }
        while (d[0] != -1) {
            cycle(d);
        }
        d.pop_front();
        return d;
    }
};