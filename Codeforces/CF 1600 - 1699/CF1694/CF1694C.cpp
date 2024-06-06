#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool ok = a[0] >= 0, all_zero = false;
    for (int i = 0; i + 1 < n; ++i) {
        if (b[i] > a[i] || (all_zero && a[i] > b[i])) {
            ok = false;
            continue;
        }
        if (a[i] == b[i]) {
            all_zero = true;
        }
        b[i + 1] -= a[i] - b[i];
    }
    if (ok && b[n - 1] == a[n - 1]) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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