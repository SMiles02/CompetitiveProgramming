struct bellman_ford {
    const long long INF = 1e18;
    int n;
    vector<array<int, 3>> edges;
    bellman_ford(int n) : n(n) {}
    void add_directed_edge(int x, int y, int z) {
        edges.push_back({x, y, z});
    }
    void add_undirected_edge(int x, int y, int z) {
        edges.push_back({x, y, z});
        edges.push_back({y, x, z});
    }
    vector<int> get_negative_cycle() {
        int x;
        vector<int> p(n + 1);
        vector<long long> dist(n + 1);
        for (int _ = 0; _ < n; ++_) {
            x = -1;
            for (auto [a, b, c] : edges)
                if (dist[a] + c < dist[b]) {
                    dist[b] = dist[a] + c;
                    p[b] = a;
                    x = b;
                }
        }
        if (x == -1)
            return {-1};
        for (int _ = 0; _ < n; ++_)
            x = p[x];
        vector<int> neg_cycle = {x};
        while (p[x] != neg_cycle[0])
            neg_cycle.push_back(x = p[x]);
        neg_cycle.push_back(p[x]);
        reverse(neg_cycle.begin(), neg_cycle.end());
        return neg_cycle;
    }
};