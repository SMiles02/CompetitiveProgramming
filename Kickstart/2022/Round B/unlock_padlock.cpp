#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = 1e18;
int n, d;
ll dp[400][400][2];

int cost(int x, int y) {
    if (x > y)
        swap(x, y);
    return min(y - x, x + d - y);
}

void solve() {
    cin >> n >> d;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    // dp[l][r][0 / 1]
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 2; ++k)
                dp[i][j][k] = INF;
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < 2; ++k)
            dp[i][i][k] = 0;
    for (int j = 1; j < n; ++j)
        for (int i = j - 1; i >= 0; --i) {
            dp[i][j][0] = min(dp[i + 1][j][0] + cost(a[i], a[i + 1]), dp[i + 1][j][1] + cost(a[i], a[j]));
            dp[i][j][1] = min(dp[i][j - 1][0] + cost(a[j], a[i]), dp[i][j - 1][1] + cost(a[j], a[j - 1]));
        }
    cout << min(dp[0][n - 1][0] + cost(0, a[0]), dp[0][n - 1][1] + cost(0, a[n - 1])) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}