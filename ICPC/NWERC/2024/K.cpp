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
        bool operator<(const next_shortest &rhs) const {
            return dist > rhs.dist;
        }
    };
    int n;
    vector<vector<Edge>> e;
    dijkstra(int n) : n(n), e(n + 1) {}
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
            if (cur_dist > d[cur_node]) continue;
            for (auto i : e[cur_node]) {
                if (cur_dist + i.weight < d[i.target]) {
                    d[i.target] = cur_dist + i.weight;
                    pq.push({i.target, d[i.target]});
                }
            }
        }
        return d;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    dijkstra graph(n);
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        graph.add_undirected_edge(x, y, z);
    }
    vector<pair<long long, double>> kr(k), pb(k);
    bool def = false;
    for (auto& i : kr) {
        cin >> i.first >> i.second;
        def |= i.second == 1;
    }
    if (!def) {
        cout << "impossible";
        return 0;
    }
    vector<long long> d1 = graph.shortest_path(1), dn = graph.shortest_path(n);
    for (int i = 0; i < k; ++i) {
        pb[i] = {d1[kr[i].first] + dn[kr[i].first], kr[i].second};
    }
    double ans = 0, p = 1;
    sort(pb.begin(), pb.end());
    for (auto i : pb) {
        ans += i.first * p * i.second;
        p *= 1 - i.second;
    }
    cout << fixed << setprecision(25) << ans;
    return 0;
}