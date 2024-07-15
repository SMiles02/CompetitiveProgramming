#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    if (n == 1) {
        cout << "0\n";
        return;
    }
    if (n <= k) {
        cout << "1\n";
        return;
    }
    while (n > 1) {
        ++ans;
        n -= k - 1;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}