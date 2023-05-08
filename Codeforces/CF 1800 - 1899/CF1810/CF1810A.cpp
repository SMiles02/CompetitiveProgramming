#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    bool ok = false;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        ok |= k <= i;
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}