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
    vector<long long> shortest_path(int x) {
        vector<long long> dist(n + 1, INF);
        dist[x] = 0;
        for (int _ = 1; _ < n; ++_)
            for (auto [a, b, c] : edges)
                if (dist[a] != INF)
                    dist[b] = min(dist[b], dist[a] + c);
        return dist;
    }
};