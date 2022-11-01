#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cur = 0, mx = 0;
    long long ans = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        if (a[i] > cur)
            ans += a[i] - cur;
        cur = a[i];
    }
    if (ans == mx)
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