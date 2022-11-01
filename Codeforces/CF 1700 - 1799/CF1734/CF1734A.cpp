#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 1e9;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 2; i < n; ++i)
        ans = min(ans, a[i] - a[i - 2]);
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