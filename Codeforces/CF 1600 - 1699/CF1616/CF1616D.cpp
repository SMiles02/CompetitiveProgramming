#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, b = 0;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> x;
    vector<int> dp(n + 1);
    // dp[i] = maximum answer for a[1 ... i] in which i is selected
    for (int i = 1; i <= n; ++i) {
        if (n > 2 && a[i] + a[i - 1] + a[i - 2] < x * 3)
            b = i - 2;
        if (n > 1 && a[i] + a[i - 1] < x * 2)
            b = i - 1;
        if (b == 0)
            dp[i] = i;
        else
            dp[i] = dp[b - 1] + i - b;
    }
    cout << max(dp[n - 1], dp[n]) << "\n";
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}