#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long ans = 0;
    cin >> n;
    int a[n], x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        ans += min(x, y);
        a[i] = max(x, y);
    }
    sort(a, a + n);
    cout << (ans + a[n - 1]) * 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}