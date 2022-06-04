#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 3005;
double dp[N][N], powers[N];
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, l;
    double p, ans = 0;
    cin >> n >> l >> p;
    powers[0] = 1;
    for (int i = 1; i < N; ++i)
        powers[i] = powers[i - 1] * p;
    dp[0][n] = 1;
    for (int i = 0; i < l; ++i) {
        for (int j = n; j > 0; --j) {
            if (j < n)
                dp[i][j] += dp[i][j + 1] * powers[j + 1];
            if (j == 1)
                dp[i + 1][j] += dp[i][j] * 0.5;
            else {
                dp[i + 1][j] += dp[i][j] * (1 - powers[j]) * 0.5;
                dp[i + 1][j - 1] += dp[i][j] * (1 - powers[j]) * 0.5;
            }
        }
        // for (int j = 1; j <= n; ++j)
        //     cout << dp[i][j] << " ";
        // cout << "\n";
    }
    // for (int j = 1; j <= n; ++j)
    //     cout << dp[l][j] << " ";
    // cout << "\n";
    for (int j = 1; j <= n; ++j)
        ans += dp[l][j];
    cout << fixed << setprecision(10) << ans;
    return 0;
}