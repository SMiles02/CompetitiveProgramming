#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y, cur = 0;
    cin >> n >> x >> y;
    if (x > y)
        swap(x, y);
    if (x > 0 || y == 0 || (n - 1) % y) {
        cout << "-1\n";
        return;
    }
    for (int i = 2; i <= n; ++i) {
        if (i % y == 2 % y)
            cur = i;
        cout << cur << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}