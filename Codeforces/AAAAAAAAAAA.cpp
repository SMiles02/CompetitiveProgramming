#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k, n;
    cin >> k >> n;
    int a[n + 1][k];
    for (int i = 0; i < k; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[j][i];
    vector<vector<ll>> dp(n + 1, vector<ll>(1 << k, 1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < (1 << k); ++j)
            for (int x = 0; x < k; ++x)
                if (j & (1 << x))
                    dp[i][j] = min({dp[i][j], dp[i - 1][j], dp[i - 1][j ^ (1 << x)] + a[i][x]});
        dp[i][0] = 0;
    }
    cout << dp[n][(1 << k) - 1];
    return 0;
}