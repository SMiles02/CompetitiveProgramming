#include <bits/stdc++.h>
#define ll long long
using namespace std;

int d(int x, int y) {
    return abs(x - y);
}

void solve() {
    int n, p;
    cin >> n >> p;
    vector<vector<int>> a(n + 1, vector<int>(p));
    long long dp[n + 1][2];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < p; ++j)
            cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = d(a[i][0], a[i][p - 1]) + min(dp[i - 1][0] + d(a[i - 1][0], a[i][p - 1]), dp[i - 1][1] + d(a[i - 1][p - 1], a[i][p - 1]));
        dp[i][1] = d(a[i][0], a[i][p - 1]) + min(dp[i - 1][0] + d(a[i - 1][0], a[i][0]), dp[i - 1][1] + d(a[i - 1][p - 1], a[i][0]));
    }
    cout << min(dp[n][0], dp[n][1]) << "\n";
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