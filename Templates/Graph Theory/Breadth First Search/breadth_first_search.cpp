struct bfs {
    const int INF = 1e9;
    int n;
    vector<vector<int>> edges;
    bfs(int n) : n(n), edges(n + 1) {}
    void add_directed_edge(int x, int y) {
        edges[x].push_back(y);
    }
    void add_undirected_edge(int x, int y) {
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<int> run_bfs(int source) {
        vector<int> dist(n + 1, INF);
        queue<int> q;
        dist[source] = 0;
        q.push(source);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i : edges[x])
                if (dist[i] == INF) {
                    dist[i] = dist[x] + 1;
                    q.push(i);
                }
        }
        return dist;
    }
};