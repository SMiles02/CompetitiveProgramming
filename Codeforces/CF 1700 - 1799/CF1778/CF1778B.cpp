#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, d, k, ans = 1e9;
    cin >> n >> m >> d;
    int pos[n + 1], a[m];
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        pos[k] = i;
    }
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    for (int i = 1; i < m; ++i) {
        if (pos[a[i - 1]] > pos[a[i]] || pos[a[i]] > pos[a[i - 1]] + d) {
            cout << "0\n";
            return;
        }
        ans = min(ans, pos[a[i]] - pos[a[i - 1]]);
        if (d < n - 1)
            ans = min(ans, pos[a[i - 1]] + d + 1 - pos[a[i]]);
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