#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, mx = 0;
    cin >> n;
    int a[n], t[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        mx = max(mx, t[i]);
    }
    double l = mx, r = mx + 1e8, m;
    for (int _ = 0; _ < 80; ++_) {
        m = l + (r - l) / 2;
        double x = 0, y = 1e8;
        for (int i = 0; i < n; ++i) {
            x = max(x, - m + t[i] + a[i]);
            y = min(y, m - t[i] + a[i]);
        }
        if (x > y)
            l = m;
        else
            r = m;
    }
    double x = 0, y = 1e8;
    for (int i = 0; i < n; ++i) {
        x = max(x, - l + t[i] + a[i]);
        y = min(y, l - t[i] + a[i]);
    }
    cout << fixed << setprecision(20) << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}