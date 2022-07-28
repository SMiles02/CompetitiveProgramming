#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x = 0;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
        x = max(x, a[i] - b[i]);
    for (int i = 0; i < n; ++i)
        if (max(0, a[i] - x) != b[i]) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}