#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q, l, r, m, x;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    for (int i = 1; i < n; ++i)
        a[i] += a[i - 1];
    while (q--) {
        cin >> x;
        if (x > a[n - 1]) {
            cout << "-1\n";
            continue;
        }
        l = 0;
        r = n - 1;
        while (l < r) {
            m = l + (r - l) / 2;
            if (a[m] < x)
                l = m + 1;
            else
                r = m;
        }
        cout << l + 1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}