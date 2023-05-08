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

const int N = 5e4 + 1;
bitset<N> dp[N];
int from[N];
vector<int> to[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    strongly_connected_components scc(n);
    vector<array<int, 2>> e(m);
    for (int i = 0; i < m; ++i) {
        cin >> e[i][0] >> e[i][1];
        scc.add_edge(e[i][0], e[i][1]);
    }
    scc.build_scc();
    for (auto i : e)
        if (scc.component[i[0]] != scc.component[i[1]]) {
            ++from[scc.component[i[0]]];
            to[scc.component[i[1]]].push_back(scc.component[i[0]]);
        }
    vector<int> v;
    for (int i = 1; i <= scc.component_count; ++i)
        if (from[i] == 0)
            v.push_back(i);
    while (!v.empty()) {
        int x = v.back();
        v.pop_back();
        dp[x][x] = 1;
        for (int i : to[x]) {
            if (--from[i] == 0)
                v.push_back(i);
            dp[i] |= dp[x];
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (dp[scc.component[x]][scc.component[y]])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}