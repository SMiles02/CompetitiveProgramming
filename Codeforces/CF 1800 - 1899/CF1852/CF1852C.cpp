#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 5, C = 100;
const ll INF = 1e18;
int a[N][C];
ll dp[N][C];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        if (a[i][0] == k) {
            a[i][0] = 0;
        }
        for (int j = 1; j < C; ++j) {
            a[i][j] = a[i][j - 1] + k;
        }
        if (i == 0) {
            for (int j = 0; j < C; ++j) {
                dp[0][j] = a[0][j];
            }
        }
        else {
            for (int x = 0; x < C; ++x) {
                dp[i][x] = INF;
                for (int y = 0; y < C; ++y) {
                    dp[i][x] = min(dp[i][x], dp[i - 1][y] + max(a[i][x] - a[i - 1][y], 0));
                }
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i < C; ++i) {
        ans = min(ans, dp[n - 1][i]);
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