struct maxflow {
    int n;
    vector<vector<long long>> e;
    maxflow(int n) : n(n), e(n + 1, vector<long long>(n + 1)) { }
    void add_edge(int a, int b, int c) {
        e[a][b] += c;
    }
    bool dfs(int cur, int t, long long c, vector<vector<long long>>& ne, vector<int>& p) {
        if (cur == t) {
            return true;
        }
        for (int i = 1; i <= n; ++i) {
            if (ne[cur][i] >= c && p[i] == -1) {
                p[i] = cur;
                if (dfs(i, t, c, ne, p)) {
                    return true;
                }
            }
        }
        return false;
    }
    long long find_max_flow(int s, int t) {
        long long c = 0, ans = 0;
        vector<vector<long long>> ne = e;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                c += ne[i][j];
            }
        }
        while (c > 0) {
            vector<int> p(n + 1, -1);
            p[s] = s;
            if (!dfs(s, t, c, ne, p)) {
                c /= 2;
                continue;
            }
            int cur = t;
            while (cur != s) {
                ne[p[cur]][cur] -= c;
                ne[cur][p[cur]] += c;
                cur = p[cur];
            }
            ans += c;
        }
        return ans;
    }
};