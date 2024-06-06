#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k, x = 0, y = 0, z = 0;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    vector<bool> c(k + 1), d(k + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= k) {
            c[a[i]] = true;
        }
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        if (b[i] <= k) {
            d[b[i]] = true;
        }
    }
    for (int i = 1; i <= k; ++i) {
        if (c[i] && d[i]) {
            ++z;
        }
        else if (c[i]) {
            ++x;
        }
        else if (d[i]) {
            ++y;
        }
        else {
            cout << "NO\n";
            return;
        }
    }
    if (min(x, y) + z < k / 2) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}