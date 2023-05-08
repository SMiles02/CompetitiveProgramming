#include <bits/stdc++.h>
using namespace std;

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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    bellman_ford graph(n);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        graph.add_directed_edge(x, y, z);
    }
    vector<int> ans = graph.get_negative_cycle();
    if (ans[0] == -1)
        cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i : ans)
            cout << i << " ";
    }
    return 0;
}