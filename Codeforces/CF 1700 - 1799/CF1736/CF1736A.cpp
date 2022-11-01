#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x = 0, ans = 0;;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        x += a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        x -= b[i];
        ans += (a[i] != b[i]);
    }
    cout << min(ans, abs(x) + 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}