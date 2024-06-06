#include <bits/stdc++.h>
using namespace std;

struct maxflow {
    int n;
    vector<vector<long long>> e;
    maxflow(int n) : n(n), e(n + 1, vector<long long>(n + 1)) { }
    void add_edge(int a, int b, int c) {
        e[a][b] += c;
    }
    bool dfs(int cur, int t, long long c, vector<vector<long long>>& ne, vector<int>& p) {
        if (cur == t) {
            return true;
        }
        for (int i = 1; i <= n; ++i) {
            if (ne[cur][i] >= c && p[i] == -1) {
                p[i] = cur;
                if (dfs(i, t, c, ne, p)) {
                    return true;
                }
            }
        }
        return false;
    }
    void find_flows(int s, int t) {
        long long c = 1, ans = 0;
        vector<vector<long long>> ne = e;
        vector<vector<int>> paths;
        while (c > 0) {
            vector<int> p(n + 1, -1);
            p[s] = s;
            if (!dfs(s, t, c, ne, p)) {
                c /= 2;
                continue;
            }
            int cur = t;
            while (cur != s) {
                ne[p[cur]][cur] -= c;
                ne[cur][p[cur]] += c;
                cur = p[cur];
            }
            ans += c;
        }
        for (int i = 0; i < ans; ++i) {
            paths.push_back({s});
            int cur = s;
            while (cur != t) {
                for (int i = 1; i <= n; ++i) {
                    if (ne[cur][i] < e[cur][i]) {
                        ++ne[cur][i];
                        --ne[i][cur];
                        cur = i;
                        break;
                    }
                }
                paths.back().push_back(cur);
            }
        }
        cout << ans << "\n";
        for (auto i : paths) {
            cout << i.size() << "\n";
            for (int j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    maxflow g(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        g.add_edge(a, b, 1);
    }
    g.find_flows(1, n);
    return 0;
}