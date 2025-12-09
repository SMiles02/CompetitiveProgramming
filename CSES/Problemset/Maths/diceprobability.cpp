#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a, b, k;
    cin >> n >> a >> b;
    vector<vector<double>> dp(n + 1, vector<double>(n * 6 + 7));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n * 6; ++j) {
            for (int k = 1; k <= 6; ++k) {
                dp[i + 1][j + k] += dp[i][j] / 6;
            }
        }
    }
    double ans = 0;
    for (int i = a; i <= b; ++i) {
        ans += dp[n][i];
    }
    cout << fixed << setprecision(6) << ans;
    return 0;
}