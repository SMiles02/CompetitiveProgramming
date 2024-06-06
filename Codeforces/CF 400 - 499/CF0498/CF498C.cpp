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
    long long find_max_flow(int s, int t) {
        long long c = 0, ans = 0;
        vector<vector<long long>> ne = e;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                c += ne[i][j];
            }
        }
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
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k, c;
    cin >> n >> m;
    k = (n + m) * 9;
    c = n;
    maxflow graph(n * 9 + m * 9);
    vector<int> a(n + 1);
    vector<vector<array<int, 2>>> factors(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            graph.add_edge(k - 1, i, 32);
        }
        else {
            graph.add_edge(i, k, 32);
        }
        cin >> a[i];
        for (int j = 2; j * j <= a[i]; ++j) {
            if (a[i] % j) {
                continue;
            }
            int tmp = 0;
            factors[i].push_back({j, ++c});
            while (a[i] % j == 0) {
                ++tmp;
                a[i] /= j;
            }
            if (i & 1) {
                graph.add_edge(i, c, tmp);
            }
            else {
                graph.add_edge(c, i, tmp);
            }
        }
        if (a[i] > 1) {
            factors[i].push_back({a[i], ++c});
            if (i & 1) {
                graph.add_edge(i, c, 1);
            }
            else {
                graph.add_edge(c, i, 1);
            }
        }
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (y & 1) {
            swap(x, y);
        }
        for (auto i : factors[x]) {
            for (auto j : factors[y]) {
                if (i[0] == j[0]) {
                    graph.add_edge(i[1], j[1], 32);
                }
            }
        }
    }
    cout << graph.find_max_flow(k - 1, k) << "\n";
    return 0;
}