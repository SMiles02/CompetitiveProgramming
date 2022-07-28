#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, ans = 1e9, l, r, m;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int mn = 0; mn <= a[0]; ++mn) {
        int mx = mn;
        for (int i = 0; i < n; ++i) {
            l = 1;
            r = k;
            while (l < r) {
                m = l + (r - l) / 2 + 1;
                if (a[i] / m < mn)
                    r = m - 1;
                else
                    l = m;
            }
            mx = max(mx, a[i] / l);
        }
        ans = min(ans, mx - mn);
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