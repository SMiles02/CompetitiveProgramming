#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, cur = 0;
    cin >> n >> x;
    int a[n];
    for (int _ = 0; _ < 3; ++_) {
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n && (x | a[i]) == x; ++i)
            cur |= a[i];
    }
    if (cur == x)
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