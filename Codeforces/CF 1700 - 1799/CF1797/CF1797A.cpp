#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a, b, c, d, ans = 4;
    cin >> n >> m;
    cin >> a >> b >> c >> d;
    if ((a == 1 || a == n) && (b == 1 || b == m))
        ans = min(ans, 2);
    if ((a == 1 || a == n) || (b == 1 || b == m))
        ans = min(ans, 3);
    if ((c == 1 || c == n) && (d == 1 || d == m))
        ans = min(ans, 2);
    if ((c == 1 || c == n) || (d == 1 || d == m))
        ans = min(ans, 3);
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