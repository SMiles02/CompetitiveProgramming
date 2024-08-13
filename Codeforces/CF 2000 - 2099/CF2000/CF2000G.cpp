#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

struct dijkstra {
    using S = int; // regular edge weight type, change if needed
    using T = long long; // maximum possible distance type, change if needed
    const T INF = 1e18;
    struct Edge {
        int target;
        S bus, walk;
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
    void add_undirected_edge(int x, int y, S bus, S walk) {
        e[x].push_back({y, bus, walk});
        e[y].push_back({x, bus, walk});
    }
    vector<T> shortest_path(int src, T t1, T t2) {
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
            for (auto i : e[cur_node]) {
                T tot_dist = INF;
                if (cur_dist <= t1) {
                    if (cur_dist + i.bus <= t1) {
                        tot_dist = cur_dist + i.bus;
                    }
                    else {
                        tot_dist = min(cur_dist + i.walk, t2 + i.bus);
                    }
                }
                else if (cur_dist >= t2) {
                    tot_dist = cur_dist + i.bus;
                }
                else {
                    tot_dist = min(cur_dist + i.walk, t2 + i.bus);
                }
                if (tot_dist < d[i.target]) {
                    d[i.target] = tot_dist;
                    pq.push({i.target, d[i.target]});
                }
            }
        }
        return d;
    }
};

void solve() {
    int n, m, t0, t1, t2;
    cin >> n >> m;
    cin >> t0 >> t1 >> t2;
    dijkstra graph(n);
    while (m--) {
        int u, v, b, w;
        cin >> u >> v >> b >> w;
        graph.add_undirected_edge(u, v, b, w);
    }
    vector<long long> dist = graph.shortest_path(n, t0 - t2, t0 - t1);
    if (dist[1] > t0) {
        cout << "-1\n";
    }
    else {
        cout << t0 - dist[1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}