#include <bits/stdc++.h>
using namespace std;

struct bfs {
    const int INF = 1e9;
    int n;
    vector<vector<int>> edges;
    bfs(int n) : n(n), edges(n + 1) {}
    void add_undirected_edge(int x, int y) {
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<int> run_bfs(int source) {
        vector<int> dist(n + 1, INF);
        queue<int> q;
        dist[source] = 0;
        q.push(source);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i : edges[x])
                if (dist[i] == INF) {
                    dist[i] = dist[x] + 1;
                    q.push(i);
                }
        }
        return dist;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    bfs graph(n * 2);
    while (m--) {
        int x, y;
        cin >> x >> y;
        graph.add_undirected_edge(x, y + n);
        graph.add_undirected_edge(x + n, y);
    }
    vector<vector<int>> dist(n * 2 + 1);
    for (int i = 1; i <= n; ++i) {
        dist[i] = graph.run_bfs(i);
    }

    while (q--) {
        int a, b, x;
        cin >> a >> b >> x;
        if (dist[a][b + n * (x & 1)] <= x) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}