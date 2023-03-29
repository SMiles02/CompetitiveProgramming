#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, d, w, x = 0, y, ans = 0;
    cin >> n >> k >> d >> w;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    while (x < n) {
        ++ans;
        for (int i = x; i < min(x + k, n); ++i) {
            if (max(a[x] + w, a[i]) <= min(a[x] + w + d, a[i] + w))
                y = i + 1;
            else
                break;
        }
        x = y;
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