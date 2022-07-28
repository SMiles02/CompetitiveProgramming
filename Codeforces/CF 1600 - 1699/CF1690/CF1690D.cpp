#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, ans = 1e9;
    cin >> n >> k;
    string s;
    cin >> s;
    int p[n + 1];
    p[0] = 0;
    for (int i = 0; i < n; ++i)
        p[i + 1] = p[i] + (s[i] == 'W');
    for (int i = k; i <= n; ++i)
        ans = min(ans, p[i] - p[i - k]);
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