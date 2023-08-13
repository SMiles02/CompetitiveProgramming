#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 103;
int dp[N][N][2];

int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

void solve() {
    int n, a, b, x, y, ans = 0;
    cin >> n >> a >> b >> x >> y;
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            dp[i][j][0] = dp[i][j][1] = 0;
        }
    }
    if (x == 1) {
        if (a == 1) {
            dp[1][n][0] = 1;
        }
    }
    else if (y == 1) {
        if (b == n) {
            dp[1][n][1] = 1;
        }
    }
    else {
        if (a != 1) {
            dp[1][n][0] = 1;
        }
        if (b != n) {
            dp[1][n][1] = 1;
        }
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 1; i <= k; ++i) {
            int j = i + n - k, cur = add(dp[i - 1][j][0], dp[i][j + 1][1]);
            if ((i != a && i != b) || (i == a && x == k) || (i == b && y == k)) {
                dp[i][j][0] = cur;
            }
            if ((j != a && j != b) || (j == a && x == k) || (j == b && y == k)) {
                dp[i][j][1] = cur;
            }
        }
    }
    for (int i = 2; i < n; ++i) {
        ans = add(ans, dp[i][i][0]);
    }
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