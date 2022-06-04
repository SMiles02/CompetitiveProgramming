#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, ans = 1e9, cur = 0;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < y; ++x) {
            cur = 0;
            for (int j = 0; j < m; ++j)
                cur += abs(s[x][j] - s[y][j]);
            ans = min(ans, cur);
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