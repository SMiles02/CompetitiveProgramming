#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve() {
    int x, y, l = 1, r = 1e6, m;
    cin >> x >> y;
    while (l < r) {
        m = l + (r - l) / 2 + 1;
        if ((1LL * m * (m - 1)) / 2 + x <= y) {
            l = m;
        }
        else {
            r = m - 1;
        }
    }
    cout << l << "\n";
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