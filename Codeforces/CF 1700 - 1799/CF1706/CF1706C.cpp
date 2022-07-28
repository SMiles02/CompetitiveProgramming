#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], c[n];
    ll ans = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i + 1 < n; ++i)
        c[i] = max(max(a[i - 1], a[i + 1]) + 1 - a[i], 0);
    if (n & 1)
        for (int i = 1; i < n; i += 2)
            ans += c[i];
    else {
        vector<ll> dp(n);
        dp[1] = c[1];
        dp[2] = c[2];
        for (int i = 3; i + 1 < n; ++i) {
            if (i & 1)
                dp[i] = dp[i - 2] + c[i];
            else
                dp[i] = min(dp[i - 3], dp[i - 2]) + c[i];
        }
        ans = min(dp[n - 3], dp[n - 2]);
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