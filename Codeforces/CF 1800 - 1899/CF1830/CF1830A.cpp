#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int dp[N];
vector<array<int, 2>> e[N];

void dfs(int c, int p, int j) {
    for (auto [x, y] : e[c])
        if (x != p) {
            dp[x] = dp[c] + (j >= y);
            dfs(x, c, y);
        }
}

void solve() {
    int n, mx = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        e[x].push_back({y, i});
        e[y].push_back({x, i});
    }
    dfs(1, 0, n);
    for (int i = 1; i <= n; ++i)
        mx = max(mx, dp[i]);
    cout << mx << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}