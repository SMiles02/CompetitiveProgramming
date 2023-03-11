#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    ll ans = 0;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        ans += max(a[i] - a[i - 1] - 1, 0);
        if (a[i] > a[i - 1] + 1)
            a[i] = a[i - 1] + 1;
    }
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