#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> sz(n);
    for (int i = 0; i < n; ++i) {
        cin >> sz[i];
        for (int j = 1, k; j < sz[i]; ++j) {
            cin >> k;
        }
    }
    for (int i = 19; i >= 0; --i) {
        for (int j = 0; j < sz.size(); ++j) {
            if (sz[j] >= (1 << i)) {
                sz[j] -= 1 << i;
                ans ^= 1 << i;
                break;
            }
        }
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