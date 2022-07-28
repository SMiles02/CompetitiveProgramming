#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n + 1];
    array<int, 4> dp[n + 1], ans = {0, 69, 69, 69};
    map<int, int> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (m[a[i]]) {
            if (dp[m[a[i]]][0] - i + m[a[i]] + 2 > 0)
                dp[i] = {dp[m[a[i]]][0] - i + m[a[i]] + 2, dp[m[a[i]]][1], i, a[i]};
            else
                m[a[i]] = 0;
        }
        if (!m[a[i]])
            dp[i] = {1, i, i, a[i]};
        m[a[i]] = i;
        ans = max(ans, dp[i]);
    }
    cout << ans[3] << " " << ans[1] << " " << ans[2] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}