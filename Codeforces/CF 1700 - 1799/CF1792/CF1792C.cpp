#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    int a[n + 1], p[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 1; i < n; ++i)
        if (p[i] > p[i + 1])
            ans = max(ans, min(i, n - i));
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