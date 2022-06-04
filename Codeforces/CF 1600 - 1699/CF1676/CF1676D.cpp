#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, ans = 0;
    cin >> n >> m;
    int a[n][m];
    map<int, int> x, y;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            x[i - j] += a[i][j];
            y[i + j] += a[i][j];
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans = max(ans, x[i - j] + y[i + j] - a[i][j]);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}