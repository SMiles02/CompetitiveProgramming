#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cnt = 0, c, d, unq = 0;
    cin >> n >> c >> d;
    int a[n * 2];
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++m[a[i]];
    }
    for (int i = 0; i < n; ++i)
        a[i + n] = i + 1;
    sort(a, a + n * 2);
    long long ans = 1e18, cur = 0;
    for (int i = 0; i < n * 2; ++i) {
        unq += min(m[a[i]], 1);
        cnt += m[a[i]];
        cur += 1LL * max(m[a[i]] - 1, 0) * c;
        ans = min(ans, cur + 1LL * (n - cnt) * c + 1LL * (a[i] - unq) * d);
        m[a[i]] = 0;
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