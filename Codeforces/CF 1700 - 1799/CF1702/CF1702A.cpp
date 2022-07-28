#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m = 1, ans = 1e18;
    cin >> n;
    while (m <= n) {
        ans = min(ans, n - m);
        m *= 10;
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