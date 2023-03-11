#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0, best = -4, cur;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += a[i];
    }
    for (int i = 1; i < n; ++i) {
        cur = a[i] + a[i - 1];
        best = max(best, - cur * 2);
    }
    cout << ans + best << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}