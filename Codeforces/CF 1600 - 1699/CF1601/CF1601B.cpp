#include <bits/stdc++.h>
using namespace std;

struct dijkstra {
    using S = int; // regular edge weight type, change if needed
    using T = int; // maximum possible distance type, change if needed
    const T INF = 1e9;
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
    vector<array<int, 2>> shortest_path(int src) {
        vector<array<int, 2>> d(n + 1, {INF, INF});
        d[src] = {0, 0};
        priority_queue<next_shortest> pq;
        pq.push({src, 0});
        while (!pq.empty()) {
            int cur_node = pq.top().node, cur_dist = pq.top().dist;
            pq.pop();
            if (cur_dist > d[cur_node][0])
                continue;
            for (auto i : e[cur_node])
                if (cur_dist + i.weight < d[i.target][0]) {
                    d[i.target] = {cur_dist + i.weight, cur_node};
                    pq.push({i.target, d[i.target][0]});
                }
        }
        return d;
    }
};

int n;

void build_dijk(int i, int l, int r, dijkstra& graph) {
    if (l == r) {
        graph.add_directed_edge(n + i, l, 0);
        return;
    }
    graph.add_directed_edge(n + i, n + i * 2, 0);
    graph.add_directed_edge(n + i, n + i * 2 + 1, 0);
    build_dijk(i * 2, l, l + (r - l) / 2, graph);
    build_dijk(i * 2 + 1, l + (r - l) / 2 + 1, r, graph);
}

void query(int i, int l, int r, int ql, int qr, vector<int>& v) {
    if (qr < l || r < ql) {
        return;
    }
    if (ql <= l && r <= qr) {
        v.push_back(i);
        return;
    }
    query(i * 2, l, l + (r - l) / 2, ql, qr, v);
    query(i * 2 + 1, l + (r - l) / 2 + 1, r, ql, qr, v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    dijkstra graph(n * 5);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    build_dijk(1, 0, n, graph);
    for (int i = 1; i <= n; ++i) {
        vector<int> v;
        query(1, 0, n, i + b[i] - a[i + b[i]], i + b[i], v);
        for (int j : v) {
            graph.add_directed_edge(i, n + j, 1);
        }
    }
    vector<array<int, 2>> d = graph.shortest_path(n);
    if (d[0][0] == graph.INF) {
        cout << "-1\n";
    }
    else {
        cout << d[0][0] << "\n";
        vector<int> ans = {0};
        while (d[ans.back()][1] != n) {
            ans.push_back(d[ans.back()][1]);
        }
        while (!ans.empty()) {
            if (ans.back() <= n) {
                cout << ans.back() << " ";
            }
            ans.pop_back();
        }
    }
    return 0;
}