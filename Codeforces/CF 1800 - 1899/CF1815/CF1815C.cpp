#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int n, m, mx = 1, ans = 0;
    cin >> n >> m;
    vector<int> d(n + 1, INF);
    vector<vector<int>> e(n + 1);
    d[1] = 1;
    while (m--) {
        int x, y;
        cin >> x >> y;
        e[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans += d[x];
        mx = max(mx, d[x]);
        for (auto i : e[x])
            if (d[i] == INF) {
                d[i] = d[x] + 1;
                q.push(i);
            }
    }
    for (int i = 1; i <= n; ++i)
        if (d[i] == INF) {
            cout << "INFINITE\n";
            return;
        }
    cout << "FINITE\n" << ans << "\n";
    vector<int> v;
    for (int i = mx; i >= 1; --i) {
        for (int j = 1; j <= n; ++j)
            if (d[j] == i)
                v.push_back(j);
        for (int j = ((int)v.size()) - 1; j >= 0; --j)
            cout << v[j] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}