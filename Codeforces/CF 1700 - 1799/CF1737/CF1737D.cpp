#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

void solve() {
    int n, m, x, y, z;
    cin >> n >> m;
    vector<vector<int>> d(n + 1, vector<int>(n + 1, 1e9));
    vector<vector<ll>> e(n + 1, vector<ll>(n + 1, 1e12));
    ll ans = 1e18;
    for (int i = 0; i < m; ++i) {
        cin >> x >> y >> z;
        e[x][y] = min(e[x][y], (ll)z);
        e[y][x] = min(e[y][x], (ll)z);
        d[x][y] = d[y][x] = 1;
    }
    for (int i = 1; i <= n; ++i)
        d[i][i] = 0;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    // cout << d[1][n] << " " << e[1][n] << "\n";
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                for (int k = 1; k <= n; ++k) {
                    // if (i == 8 && j == 4 && k == 7) {
                    //     cout << e[i][k] << "\n";
                    //     cout << e[i][j] << " " << (d[j][k] + 1) << "\n";
                    // }
                    e[i][k] = e[k][i] = min(e[i][k], e[i][j] * (d[j][k] + 1));
                }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                ans = min(ans, e[i][j] * (d[1][n] + min(d[i][1], d[i][n]) + 1));
    cout << min(e[1][n], ans) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}