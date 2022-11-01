#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 1;
    cin >> n;
    int a[n], dp[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        dp[i] = 1;
        for (int j = max(i - 255, 0); j < i; ++j)
            if ((a[j] ^ i) < (a[i] ^ j))
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
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