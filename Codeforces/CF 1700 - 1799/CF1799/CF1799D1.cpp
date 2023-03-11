#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5005;
const ll INF = 1e18;
ll dp[N][N];

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n + 1], hot[k + 1], cold[k + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[0] = 0;
    for (int i = 1; i <= k; ++i)
        cin >> cold[i];
    for (int i = 1; i <= k; ++i) {
        cin >> hot[i];
        cold[i] -= hot[i];
    }
    dp[1][0] = cold[a[1]] + hot[a[1]];
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j)
            dp[i][j] = INF;
        for (int j = 0; j < i - 1; ++j) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + hot[a[i]] + cold[a[i]] * (a[i] != a[i - 1]));
            dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + hot[a[i]] + cold[a[i]] * (a[i] != a[j]));
        }
    }
    ll ans = INF;
    for (int i = 0; i < n; ++i)
        ans = min(ans, dp[n][i]);
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