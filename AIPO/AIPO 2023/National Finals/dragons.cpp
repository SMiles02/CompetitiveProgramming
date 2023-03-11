// author is incapable of using the English language

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Dijkstra {
    using S = int; // regular edge weight type, change if needed
    using T = int; // maximum possible distance type, change if needed
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
    vector<T> multisource_shortest_path(vector<int> src) {
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

const int N = 801;
int dmx[N];
vector<array<int, 2>> e[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, m, x, y, z, p = 0;
    cin >> t;
    cin >> n >> m;
    Dijkstra dijk(n);
    for (int i = 1; i <= n; ++i)
        cin >> dmx[i];
    if (t == 1) {
        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> z;
            if (z <= dmx[1])
                dijk.add_undirected_edge(x, y, z);
        }
        int ans = 0;
        vector<int> v = dijk.shortest_path(1);
        for (int i = 1; i <= n; ++i)
            if (v[i] < INF)
                ans = max(ans, dmx[i]);
        cout << ans << "\n";
    }
    else {
        vector<array<int, 3>> ed(m);
        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> z;
            ed[i] = {z, x, y};
        }
        sort(ed.begin(), ed.end());
        array<int, 2> dms[n];
        for (int i = 1; i <= n; ++i)
            dms[i - 1] = {dmx[i], i};
        sort(dms, dms + n);
        Dijkstra new_graph(n);
        for (int i = 0; i < n; ++i) {
            while (p < m && ed[p][0] <= dms[i][0]) {
                dijk.add_undirected_edge(ed[p][1], ed[p][2], ed[p][0]);
                ++p;
            }
            vector<int> v = dijk.shortest_path(dms[i][1]);
            for (int j = 1; j <= n; ++j)
                if (v[j] < INF)
                    new_graph.add_directed_edge(dms[i][1], j, v[j]);
        }
        vector<int> v = new_graph.shortest_path(1);
        cout << v[n];
    }
    return 0;
}