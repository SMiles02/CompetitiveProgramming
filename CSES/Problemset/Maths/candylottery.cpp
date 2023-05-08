#include <bits/stdc++.h>
using namespace std;

const int N = 102;
double dp[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int x = 0; x <= k; ++x)
            for (int y = 1; y <= k; ++y)
                dp[i][max(x, y)] += dp[i - 1][x] / k;
    double ans = 0;
    for (int i = 1; i <= k; ++i)
        ans += dp[n][i] * i;
    cout << fixed << setprecision(6) << ans;
    return 0;
}