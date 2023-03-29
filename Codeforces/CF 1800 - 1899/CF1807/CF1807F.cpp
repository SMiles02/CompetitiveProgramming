#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a, b, x, y, c, d, ans = 0;
    string t;
    cin >> n >> m >> a >> b >> x >> y >> t;
    if (t[0] == 'D')
        c = 1;
    else
        c = -1;
    if (t[1] == 'R')
        d = 1;
    else
        d = -1;
    set<array<int, 4>> s;
    while (true) {
        if (a == x && b == y) {
            cout << ans << "\n";
            return;
        }
        if (s.count({a, b, c, d})) {
            cout << "-1\n";
            return;
        }
        s.insert({a, b, c, d});
        bool bounce = false;
        if (a + c < 1 || n < a + c) {
            c *= -1;
            bounce = true;
        }
        if (b + d < 1 || m < b + d) {
            d *= -1;
            bounce = true;
        }
        a += c;
        b += d;
        ans += bounce;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}