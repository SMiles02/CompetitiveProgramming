#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, ans = 15;
    cin >> n;
    for (int i = 0; i < 15; ++i) {
        m = (n + i) % 32768;
        if (m == 0)
            ans = min(ans, i);
        else
            ans = min(ans, i + 15 - __builtin_ctz(m));
    }
    cout << ans << " ";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}