#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n], mn = n, mx = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
        if (a[i] == a[i - 1]) {
            mn = min(mn, i);
            mx = max(mx, i);
        }
    if (mn == n || mn == mx)
        cout << "0\n";
    else
        cout << max(1, mx - mn - 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}