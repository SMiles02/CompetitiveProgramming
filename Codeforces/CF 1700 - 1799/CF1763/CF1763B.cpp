#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

ll f(int x) {
    return (1LL * x * (x + 1)) / 2;
}

void solve() {
    int n, k, d = 0;
    cin >> n >> k;
    array<int, 2> a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i][1];
    for (int i = 0; i < n; ++i)
        cin >> a[i][0];
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        a[i][1] -= d;
        if (a[i][1] <= 0)
            continue;
        if (i > 0)
            k -= a[i][0];
        if (k <= 0) {
            cout << "NO\n";
            return;
        }
        int l = 1, r = k / a[i][0] + 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (1LL * m * k - f(m - 1) * a[i][0] < a[i][1])
                l = m + 1;
            else
                r = m;
        }
        if (1LL * l * k - f(l - 1) * a[i][0] < a[i][1]) {
            cout << "NO\n";
            return;
        }
        d += 1LL * l * k - f(l - 1) * a[i][0];
        k -= a[i][0] * (l - 1);
    }
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}