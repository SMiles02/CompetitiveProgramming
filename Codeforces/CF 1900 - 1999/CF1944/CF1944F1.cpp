#include <bits/stdc++.h>
using namespace std;

const int N = 404;
int MOD = 1e9 + 7, dp[2][N][N], p[N][N];

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

void solve() {
    int n, k;
    cin >> n >> k >> MOD;
    for (int i = 0; i < 2; ++i) {
        for (int x = 0; x <= k + 1; ++x) {
            for (int y = 0; y <= k + 1; ++y) {
                dp[i][x][y] = 0;
            }
        }
    }
    for (int y = 0; y <= k; ++y) {
        dp[0][y][0] = 1;
    }
    for (int i = 2; i <= n + 1; ++i) {
        for (int x = 0; x <= k; ++x) {
            p[x][k + 1] = 0;
            for (int y = k; y >= 0; --y) {
                p[x][y] = add(p[x][y + 1], dp[0][x][y]);
            }
        }
        for (int x = 0; x <= k; ++x) {
            for (int y = 0; y <= k; ++y) {
                dp[1][x][y] = p[y][max(y - x, 0)];
            }
        }
        for (int x = 0; x <= k + 1; ++x) {
            for (int y = 0; y <= k + 1; ++y) {
                dp[0][x][y] = dp[1][x][y];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = add(ans, dp[0][0][i]);
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