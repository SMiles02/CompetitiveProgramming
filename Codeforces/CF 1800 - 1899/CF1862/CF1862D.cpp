#include <bits/stdc++.h>
using namespace std;

void solve() {
    ll n, l = 2, r = 2e9, m;
    cin >> n;
    while (l < r) {
        m = l + (r - l) / 2;
        if ((m * (m - 1)) / 2 < n) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    if ((l * (l - 1)) / 2 == n) {
        cout << l << "\n";
    }
    else {
        cout << l - 1 + n - ((l - 1) * (l - 2)) / 2 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}