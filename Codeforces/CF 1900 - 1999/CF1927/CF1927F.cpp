#include <bits/stdc++.h>
using namespace std;

struct disjoint_set_union {
    vector<int> p, sz;
    disjoint_set_union(int n) : p(n + 1), sz(n + 1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find_set(int i) {
        return i == p[i] ? i : p[i] = find_set(p[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            p[j] = i;
            sz[i] += sz[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

struct bfs {
    const int INF = 1e9;
    int n;
    vector<vector<int>> edges;
    bfs(int n) : n(n), edges(n + 1) {}
    void add_directed_edge(int x, int y) {
        edges[x].push_back(y);
    }
    void add_undirected_edge(int x, int y) {
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<int> run_bfs(int s, int t) {
        vector<int> dist(n + 1, INF), par(n + 1), path = {t};
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i : edges[x]) {
                if (dist[i] == INF) {
                    dist[i] = dist[x] + 1;
                    par[i] = x;
                    q.push(i);
                }
            }
        }
        while (path.back() != s) {
            path.push_back(par[path.back()]);
        }
        return path;
    }
};

void solve() {
    int n, m, id = -1;
    cin >> n >> m;
    vector<array<int, 3>> e(m);
    disjoint_set_union dsu(n);
    bfs g(n);
    for (int i = 0; i < m; ++i) {
        cin >> e[i][1] >> e[i][2] >> e[i][0];
    }
    sort(e.rbegin(), e.rend());
    for (int i = 0; i < m; ++i) {
        if (dsu.connected(e[i][1], e[i][2])) {
            id = i;
        }
        else {
            dsu.unite(e[i][1], e[i][2]);
        }
    }
    for (int i = 0; i < id; ++i) {
        g.add_undirected_edge(e[i][1], e[i][2]);
    }
    vector<int> v = g.run_bfs(e[id][1], e[id][2]);
    cout << e[id][0] << " " << v.size() << "\n";
    for (int i : v) {
        cout << i << " ";
    }
    cout << "\n";
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