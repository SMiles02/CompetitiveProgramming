#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1, n + 1), a(n + 1), dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = min(dp[i - 1] + 1, v[a[i]]);
        v[a[i]] = min(v[a[i]], dp[i - 1]);
    }
    cout << n - dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}