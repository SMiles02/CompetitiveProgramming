#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    vector<vector<int>> dp(2, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
        cin >> k;
        dp[i & 1][k] = dp[1 - (i & 1)][k] + 1;
    }
    for (int i = 1; i <= n; ++i)
        cout << max(dp[0][i], dp[1][i]) << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}