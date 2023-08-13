struct heavy_light_decomposition {
    int n;
    vector<vector<int>> edges;
    vector<int> par, heavy, height, pos, head;
    heavy_light_decomposition(int n) : n(n), edges(n + 1), par(n + 1),  heavy(n + 1), height(n + 1), pos(n + 1), head(n + 1) { }
    void add_edge(int x, int y) {
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    void heavy_dfs(int c, vector<int>& sub) {
        heavy[c] = -1;
        sub[c] = 1;
        int max_size = 0;
        for (int i : edges[c]) {
            if (i != par[c]) {
                par[i] = c;
                height[i] = height[c] + 1;
                heavy_dfs(i, sub);
                sub[c] += sub[i];
                if (sub[i] > max_size) {
                    heavy[c] = i;
                    max_size = sub[i];
                }
            }
        }
    }
    void decompose(int c, int h, int& timer) {
        pos[c] = timer++;
        head[c] = h;
        if (heavy[c] != -1) {
            decompose(heavy[c], h, timer);
        }
        for (int i : edges[c]) {
            if (i != par[c] && i != heavy[c]) {
                decompose(i, i, timer);
            }
        }
    }
    void build() {
        int timer = 0;
        vector<int> sub(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (sub[i] == 0) {
                par[i] = 0;
                height[i] = 0;
                heavy_dfs(i, sub);
                decompose(i, i, timer);
            }
        }
    }
    int get_position(int x) {
        return pos[x];
    }
    vector<array<int, 2>> path_queries(int x, int y) {
        vector<array<int, 2>> queries;
        while (head[x] != head[y]) {
            if (height[head[x]] > height[head[y]]) {
                swap(x, y);
            }
            queries.push_back({pos[head[y]], pos[y]});
            y = par[head[y]];
        }
        if (height[x] > height[y]) {
            swap(x, y);
        }
        queries.push_back({pos[x], pos[y]});
        return queries;
    } 
};