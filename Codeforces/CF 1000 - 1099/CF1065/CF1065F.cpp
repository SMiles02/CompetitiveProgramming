#include <bits/stdc++.h>
using namespace std;

struct strongly_connected_components {
    int n, component_count;
    vector<vector<int>> edges, reverse_edges;
    vector<int> component, component_size;
    strongly_connected_components(int n) : n(n), edges(n + 1), reverse_edges(n + 1), component(n + 1), component_size(n + 1), component_count(0) {}
    void add_edge(int x, int y) {
        // cerr << x << " -> " << y << "\n";
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
        // cerr << n << "\n";
        vector<int> out_order;
        vector<bool> done(n + 1, false), done_reverse(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            if (!done[i]) {
                dfs(i, out_order, done);
            }
        }
        component_count = 0;
        for (int i = out_order.size() - 1; i >= 0; --i)
            if (!done_reverse[out_order[i]]) {
                ++component_count;
                component_size[component_count] = 0;
                dfs_reverse(out_order[i], done_reverse);
            }
    }
};

const int N = 1e6 + 3;
int n, k, to[N], dp[N], raw[N];
vector<int> e[N], from[N];
strongly_connected_components scc(N);

array<int, 2> dfs(int c, int h) {
    // cout << c << " " << h << " !\n";
    vector<array<int, 2>> v;
    for (int i : e[c]) {
        v.push_back(dfs(i, h + 1));
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i) {
        if (v[i][0] - h <= k) {
            // cout << v[i - 1][1] << " " << v[i][1] << " " << c << "\n"; 
            scc.add_edge(v[i - 1][1], v[i][1]);
            scc.add_edge(v[i][1], v[i - 1][1]);
        }
    }
    for (auto i : v) {
        if (i[0] - h <= k) {
            // cout << i[1] << " " << c << " " << c << "\n"; 
            scc.add_edge(i[1], c);
        }
    }
    if (v.empty()) {
        v.push_back({h, c});
    }
    return v[0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        scc.add_edge(p, i);
        e[p].push_back(i);
        // cout << p << " " << i << "\n";
    }
    dfs(1, 0);
    scc.build_scc();
    for (int i = 1; i <= n; ++i) {
        // cout << i << ": " << scc.component[i] << "\n";
    }
    for (int i = 2; i <= n; ++i) {
        if (e[i].empty()) {
            // cout << i << ": " << scc.component[i] << "\n";
            ++raw[scc.component[i]];
            dp[scc.component[i]] = raw[scc.component[i]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j : scc.edges[i]) {
            if (scc.component[i] != scc.component[j]) {
                // cerr << scc.component[i] << " -> " << scc.component[j] << "\n";
                from[scc.component[i]].push_back(scc.component[j]);
                ++to[scc.component[j]];
            }
        }
    }
    vector<int> v;
    for (int i = 1; i <= scc.component_count; ++i) {
        // cout << i
        if (to[i] == 0) {
            v.push_back(i);
        }
    }
    int max_dp = 0;
    while (!v.empty()) {
        int x = v.back();
        v.pop_back();
        // cerr << x << "\n";
        for (int i : from[x]) {
            dp[i] = max(dp[i], dp[x] + raw[i]);
            if (--to[i] == 0) {
                v.push_back(i);
            }
        }
        max_dp = max(max_dp, dp[x]);
        // cerr << x << " " << dp[x] << "\n";
    }
    cout << max_dp;
    return 0;
}