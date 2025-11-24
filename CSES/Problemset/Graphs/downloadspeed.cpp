#include <bits/stdc++.h>
using namespace std;

struct maxflow {
    int n;
    vector<int> p;
    vector<vector<long long>> e, ne;
    maxflow(int n) : n(n), p(n + 1), e(n + 1, vector<long long>(n + 1)) { }
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
            fill(p.begin(), p.end(), -1);
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
    int n, m;
    cin >> n >> m;
    maxflow g(n);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g.add_edge(a, b, c);
    }
    cout << g.find_max_flow(1, n) << "\n";
    return 0;
}