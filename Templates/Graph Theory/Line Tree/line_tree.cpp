struct line_tree {
    int N, L;
    vector<int> head, tail, tin;
    vector<vector<array<int, 2>>> sparse_table;
    line_tree(int n) : N(n), L((int)log2(n) + 2), head(n + 1), tail(n + 1), tin(n + 1), sparse_table(L, vector<array<int, 2>>(n + 1)) {
        iota(head.begin(), head.end(), 0);
        iota(tail.begin(), tail.end(), 0);
        for (int i = 1; i <= N; ++i)
            sparse_table[0][i] = {i, 0};
    }
    int find_head(int x) {
        return x == head[x] ? x : head[x] = find_head(head[x]);
    }
    int find_tail(int x) {
        return x == tail[x] ? x : tail[x] = find_tail(tail[x]);
    }
    void unite(int x, int y, int time_of_edge) {
        x = find_head(x);
        y = find_head(y);
        if (x != y) {
            int t = find_tail(x);
            sparse_table[0][t] = {y, time_of_edge};
            tail[t] = y;
            head[y] = x;
        }
    }
    void build_tree() {
        for (int j = 1; j < L; ++j)
            for (int i = 1; i <= N; ++i)
                sparse_table[j][i] = {sparse_table[j - 1][sparse_table[j - 1][i][0]][0], max(sparse_table[j - 1][i][1], sparse_table[j - 1][sparse_table[j - 1][i][0]][1])};
        vector<bool> done(N + 1);
        int timer = 0;
        for (int i = 1; i <= N; ++i)
            if (!done[i]) {
                int cur = find_head(i);
                while (!done[cur]) {
                    tin[cur] = ++timer;
                    done[cur] = true;
                    cur = sparse_table[0][cur][0];
                }
            }
    }
    int time_of_connection(int x, int y) {
        if (find_head(x) != find_head(y))
            return -1;
        if (tin[x] > tin[y])
            swap(x, y);
        int ans = 0;
        for (int i = L - 1; i >= 0; --i)
            if ((tin[y] - tin[x]) & (1 << i)) {
                ans = max(ans, sparse_table[i][x][1]);
                x = sparse_table[i][x][0];
            }
        return ans;
    }
};