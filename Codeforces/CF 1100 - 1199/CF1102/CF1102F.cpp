#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    int a[n][m];
    vector<vector<vector<int>>> dp(1 << n, vector<vector<int>>(n, vector<int>(n)));
    vector<vector<int>> edge(n, vector<int>(n, INF)), final(n, vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                edge[i][j] = min(edge[i][j], abs(a[i][k] - a[j][k]));
            }
            for (int k = 1; k < m; ++k) {
                final[i][j] = min(final[i][j], abs(a[i][k - 1] - a[j][k]));
            }
        }
    }
    for (int i = 1; i < (1 << n); ++i) {
        if (__builtin_popcount(i) == 1) {
            dp[i][__lg(i)][__lg(i)] = INF;
        }
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) == 0) {
                continue;
            }
            for (int k = 0; k < n; ++k) {
                if ((i & (1 << k)) == 0) {
                    continue;
                }
                for (int l = 0; l < n; ++l) {
                    if (l != k && (i & (1 << l)) != 0) {
                        dp[i][j][k] = max(dp[i][j][k], min(dp[i ^ (1 << k)][j][l], edge[l][k]));
                    }
                }
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            ans = max(ans, min(dp[(1 << n) - 1][j][k], final[k][j]));
        }
    }
    cout << ans;
    return 0;
}