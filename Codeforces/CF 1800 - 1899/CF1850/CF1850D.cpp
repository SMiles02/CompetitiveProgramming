#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, ans = 1;
    cin >> n >> k;
    vector<int> a(n), dp(n, 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i) {
        if (a[i] <= a[i - 1] + k) {
            dp[i] = dp[i - 1] + 1;
        }
        ans = max(ans, dp[i]);
    }
    cout << n - ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}