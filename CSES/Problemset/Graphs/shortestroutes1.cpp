#include <bits/stdc++.h>
using namespace std;
 
struct Dijkstra {
    using S = int; // regular edge weight type, change if needed
    using T = long long; // maximum possible distance type, change if needed
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
    Dijkstra(int n) : n(n), e(n + 1) {}
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
    vector<T> multisourc_shortest_path(vector<int> src) {
        vector<T> d(n + 1, INF);
        priority_queue<next_shortest> pq;
        for (int i : src) {
            d[i] = 0;
            pq.push({i, 0});
        }
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
    int n, m, a, b, c;
    cin >> n >> m;
    Dijkstra dijkstra(n);
    while (m--) {
        cin >> a >> b >> c;
        dijkstra.add_directed_edge(a, b, c);
    }
    vector<long long> d = dijkstra.shortest_path(1);
    for (int i = 1; i <= n; ++i)
        cout << d[i] << " ";
    return 0;
}