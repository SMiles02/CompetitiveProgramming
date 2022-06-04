#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<vector<int>> mex(n, vector<int>(n)), dp(n, vector<int>(n));
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            for (int k = 0; k < 100; ++k) {
                bool found = false;
                for (int l = i; l <= j; ++l)
                    if (a[l] == k)
                        found = true;
                if (!found) {
                    mex[i][j] = k;
                    break;
                }
            }
    for (int j = 0; j < n; ++j)
        for (int i = j; i >= 0; --i) {
            dp[i][j] = mex[i][j];
            for (int k = i; k < j; ++k)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
            ans += dp[i][j] + 1;
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