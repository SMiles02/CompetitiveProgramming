struct dinic {
    const long long max_possible_flow = 1e18;
    struct edge {
        int to;
        long long cap, flow;
    };
    int n;
    vector<vector<int>> adj;
    vector<int> level, cur_pos;
    vector<edge> edges;
    dinic(int n) : n(n), adj(n + 1), level(n + 1), cur_pos(n + 1) {}
    void add_edge(int x, int y, long long cap) {
        adj[x].push_back(edges.size());
        edges.push_back({y, cap, 0});
        adj[y].push_back(edges.size());
        edges.push_back({x, 0, 0});
    }
    bool bfs(int s, int t) {
        level.assign(n + 1, -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i : adj[x]) {
                const edge& e = edges[i];
                if (level[e.to] == -1 && e.flow != e.cap) {
                    level[e.to] = level[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }
    long long dfs(int cur, int t, long long flow) {
        if (cur == t) {
            return flow;
        }
        for (int& i = cur_pos[cur]; i < adj[cur].size(); ++i) {
            edge& e = edges[adj[cur][i]];
            if (level[cur] + 1 == level[e.to] && e.flow != e.cap) {
                long long flow_pushed = dfs(e.to, t, min(flow, e.cap - e.flow));
                if (flow_pushed == 0) {
                    continue;
                }
                e.flow += flow_pushed;
                edges[adj[cur][i] ^ 1].flow -= flow_pushed;
                return flow_pushed;
            }
        }
        return 0;
    }
    long long find_max_flow(int s, int t) {
        long long tot_flow = 0;
        while (bfs(s, t)) {
            cur_pos.assign(n + 1, 0);
            while (long long cur_flow = dfs(s, t, max_possible_flow)) {
                tot_flow += cur_flow;
            }
        }
        return tot_flow;
    }
};