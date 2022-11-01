#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
        ans += (a[i] + a[0] * 2 - 2) / (a[0] * 2 - 1) - 1;
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