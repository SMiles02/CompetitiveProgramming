#include <bits/stdc++.h>
using namespace std;

array<int, 2> add(array<int, 2> a, array<int, 2> b) {
    return {a[0] + b[0], a[1] + b[1]};
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    array<int, 2> dp[n / 2][2];
    dp[0][0] = {(s[0] != '0') + (s[1] != '0'), 1};
    dp[0][1] = {(s[0] != '1') + (s[1] != '1'), 1};
    for (int i = 2; i < n; i += 2) {
        dp[i / 2][0] = min(add(dp[i / 2 - 1][0], {(s[i] != '0') + (s[i + 1] != '0'), 0}), add(dp[i / 2 - 1][1], {(s[i] != '0') + (s[i + 1] != '0'), 1}));
        dp[i / 2][1] = min(add(dp[i / 2 - 1][0], {(s[i] != '1') + (s[i + 1] != '1'), 1}), add(dp[i / 2 - 1][1], {(s[i] != '1') + (s[i + 1] != '1'), 0}));
    }
    array<int, 2> ans = min(dp[n / 2 - 1][0], dp[n / 2 - 1][1]);
    cout << ans[0] << " " << ans[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}