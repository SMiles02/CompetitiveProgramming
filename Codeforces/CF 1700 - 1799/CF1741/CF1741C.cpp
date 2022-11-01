#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, ans = 2000;
    cin >> n;
    int a[n + 1], p[n + 1];
    p[0] = 0;
    map<int, int> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        m[p[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
        if (p[n] % p[i] == 0) {
            int cur = 0;
            bool ok = true;
            for (int j = p[i]; j <= p[n]; j += p[i]) {
                if (m[j])
                    cur = max(cur, m[j] - m[j - p[i]]);
                else {
                    ok = false;
                    break;
                }
            }
            if (ok)
                ans = min(ans, cur);
        }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}