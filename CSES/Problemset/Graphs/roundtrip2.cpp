#include <bits/stdc++.h>
using namespace std;

struct strongly_connected_components {
    int n, component_count;
    vector<vector<int>> edges, reverse_edges;
    vector<int> component, component_size;
    strongly_connected_components(int n) : n(n), edges(n + 1), reverse_edges(n + 1), component(n + 1), component_size(n + 1), component_count(0) {}
    void add_edge(int x, int y) {
        edges[x].push_back(y);
        reverse_edges[y].push_back(x);
    }
    void dfs(int c, vector<int>& out_order, vector<bool>& done) {
        done[c] = true;
        for (int i : edges[c])
            if (!done[i])
                dfs(i, out_order, done);
        out_order.push_back(c);
    }
    void dfs_reverse(int c, vector<bool>& done) {
        done[c] = true;
        component[c] = component_count;
        ++component_size[component_count];
        for (int i : reverse_edges[c])
            if (!done[i])
                dfs_reverse(i, done);
    }
    void build_scc() {
        vector<int> out_order;
        vector<bool> done(n + 1, false), done_reverse(n + 1, false);
        for (int i = 1; i <= n; ++i)
            if (!done[i])
                dfs(i, out_order, done);
        component_count = 0;
        for (int i = out_order.size() - 1; i >= 0; --i)
            if (!done_reverse[out_order[i]]) {
                ++component_count;
                component_size[component_count] = 0;
                dfs_reverse(out_order[i], done_reverse);
            }
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
    int n, m;
    cin >> n >> m;
    strongly_connected_components scc(n);
    bfs graph(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        scc.add_edge(x, y);
        graph.add_directed_edge(x, y);
    }
    scc.build_scc();
    for (int i = 1; i <= n; ++i)
        if (scc.component_size[scc.component[i]] > 1) {
            int cycle_end = -1;
            vector<vector<int>> v(n);
            vector<int> dist = graph.run_bfs(i), last_node(n + 1);
            for (int j = 1; j <= n; ++j)
                if (scc.component[i] == scc.component[j]) {
                    for (int k : graph.edges[j])
                        if (k == i)
                            cycle_end = j;
                    v[dist[j]].push_back(j);
                }
            for (int j = 0; j < n; ++j)
                for (int k : v[j])
                    for (int next_node : graph.edges[k])
                        if (dist[next_node] == j + 1)
                            last_node[next_node] = k;
            vector<int> ans = {i, cycle_end};
            int x = cycle_end;
            while (x != i)
                ans.push_back(x = last_node[x]);
            cout << ans.size() << "\n";
            for (int j = ans.size() - 1; j >= 0; --j)
                cout << ans[j] << " ";
            return 0;
        }
    cout << "IMPOSSIBLE\n";
    return 0;
}