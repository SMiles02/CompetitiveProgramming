#include <bits/stdc++.h>
using namespace std;

struct dijkstra {
    using S = int;
    using T = long long;
    const T INF = 1e18;
    struct Edge {
        int target;
        S weight;
    };
    struct next_shortest {
        int node;
        T dist;
        bool operator<(const next_shortest& rhs) const {
            return dist > rhs.dist;
        }
    };
    int n;
    vector<vector<Edge>> e;
    dijkstra(int n) : n(n), e(n + 1) {}
    void add_directed_edge(int x, int y, S z) {
        e[x].push_back({y, z});
    }
    void add_undirected_edge(int x, int y, S z) {
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    vector<T> shortest_path(int src) {
        vector<T> d(n + 1, INF);
        d[src] = 0;
        priority_queue<next_shortest> pq;
        pq.push({src, 0});
        while (!pq.empty()) {
            int cur_node = pq.top().node;
            T cur_dist = pq.top().dist;
            pq.pop();
            if (cur_dist > d[cur_node])
                continue;
            for (auto i : e[cur_node])
                if (cur_dist + i.weight < d[i.target]) {
                    d[i.target] = cur_dist + i.weight;
                    pq.push({i.target, d[i.target]});
                }
        }
        return d;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    dijkstra graph(n + m);
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < m; ++i) {
        int k, a;
        cin >> k;
        while (k--) {
            cin >> a;
            graph.add_directed_edge(a, n + 1 + i, c[i]);
            graph.add_directed_edge(n + 1 + i, a, 0);
        }
    }
    vector<long long> d = graph.shortest_path(1);
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << " ";
    }
    return 0;
}