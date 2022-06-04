#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x = 0, k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        x += k & 1;
    }
    cout << min(x, n - x) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}