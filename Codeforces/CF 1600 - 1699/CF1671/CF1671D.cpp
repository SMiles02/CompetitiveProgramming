#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int a[n], mn = 2e5, mx = 1;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0)
            ans += abs(a[i] - a[i - 1]);
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    if (x < mn)
        ans += min((mn - 1) * 2, min(a[0], a[n - 1]) - 1);
    else {
        if (1 < mn)
            ans += min((mn - 1) * 2, min(a[0], a[n - 1]) - 1);
        if (mx < x)
            ans += min((x - mx) * 2, x - max(a[0], a[n - 1]));
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