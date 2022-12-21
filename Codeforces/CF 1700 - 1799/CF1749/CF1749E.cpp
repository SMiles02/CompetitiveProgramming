#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

struct Dijkstra {
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n + 2, string(m + 2, '.'));
    string t;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        for (int j = 1; j <= m; ++j)
            s[i][j] = t[j - 1];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (s[i][j] == '.' && s[i - 1][j] != '#' && s[i + 1][j] != '#' && s[i][j - 1] != '#' && s[i][j + 1] != '#')
                s[i][j] = '!';
    Dijkstra helper(n * m + 2);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (s[i][j] != '.') {
                if (s[i + 1][j - 1] != '.') {
                    helper.add_directed_edge((i - 1) * m + j - 1, i * m + j - 2, s[i + 1][j - 1] == '!');
                    helper.add_directed_edge(i * m + j - 2, (i - 1) * m + j - 1, s[i][j] == '!');
                }
                if (s[i + 1][j + 1] != '.') {
                    helper.add_directed_edge((i - 1) * m + j - 1, i * m + j, s[i + 1][j + 1] == '!');
                    helper.add_directed_edge(i * m + j, (i - 1) * m + j - 1, s[i][j] == '!');
                }
            }
    for (int i = 1; i <= n; ++i) {
        if (s[i][1] != '.')
            helper.add_directed_edge(n * m, (i - 1) * m, s[i][1] == '!')
        if (s[i][m] != '.')
            helper.add_directed_edge(n * m + 1, i * m - 1, 0)
    }
    vector<int> ans = helper.shortest_path(n * m);
    if (ans[n * m + 1] == 1e9)
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}