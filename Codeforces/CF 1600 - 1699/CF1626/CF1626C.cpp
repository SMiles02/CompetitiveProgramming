#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(int x) {
    return (1LL * x * (x + 1)) / 2;
}

void solve() {
    int n, t;
    cin >> n;
    vector<ll> dp(n + 1, (1LL << 62) - 1);
    dp[0] = 0;
    vector<int> k(n + 1), h(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> k[i];
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i) {
        t = k[i] - h[i];
        for (int j = i; j > 0; --j) {
            t = min(t, k[j] - h[j]);
            if (j == 1 || (j > 1 && t >= k[j - 1]))
                dp[i] = min(dp[i], dp[j - 1] + f(k[i] - t));
        }
    }
    cout << dp[n] << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}