#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q, l, r, m, cur;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    l = 0;
    r = n - 1;
    while (l < r) {
        m = l + (r - l) / 2;
        cur = q;
        for (int i = m; i < n; ++i)
            cur -= (cur < a[i]);
        if (cur < 0)
            l = m + 1;
        else
            r = m;
    }
    string ans(n, '0');
    for (int i = 0; i < n; ++i)
        if (q >= a[i] || i >= l)
            ans[i] = '1';
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