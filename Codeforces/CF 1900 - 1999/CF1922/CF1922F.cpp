#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int dp[N][N][N], ndp[N][N][N], mdp[N][N][2];

void solve() {
    int n, x, k, ans = N;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        for (int j = 1; j <= x; ++j) {
            dp[i][i][j] = 1;
            ndp[i][i][j] = 0;
        }
        dp[i][i][k] = 0;
        ndp[i][i][k] = 1;
    }
    for (int j = 1; j <= n; ++j) {
        for (int i = j - 1; i >= 1; --i) {
            mdp[i][j][0] = mdp[i][j][1] = N;
            for (int k = 1; k <= x; ++k) {
                dp[i][j][k] = N;
                ndp[i][j][k] = N;
                for (int s = i; s < j; ++s) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i][s][k] + dp[s + 1][j][k]);
                    ndp[i][j][k] = min(ndp[i][j][k], ndp[i][s][k] + ndp[s + 1][j][k]);
                }
                dp[i][j][k] = min(dp[i][j][k], ndp[i][j][k] + 1);
                ndp[i][j][k] = min(ndp[i][j][k], dp[i][j][k] + 1);
                if (dp[i][j][k] < mdp[i][j][1]) {
                    mdp[i][j][1] = dp[i][j][k];
                }
                if (mdp[i][j][1] < mdp[i][j][0]) {
                    swap(mdp[i][j][0], mdp[i][j][1]);
                }
            }
            for (int k = 1; k <= x; ++k) {
                ndp[i][j][k] = min(ndp[i][j][k], mdp[i][j][mdp[i][j][0] == dp[i][j][k]]);
                dp[i][j][k] = min(dp[i][j][k], ndp[i][j][k] + 1);
            }
        }
    }
    for (int i = 1; i <= x; ++i) {
        ans = min(ans, dp[1][n][i]);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}