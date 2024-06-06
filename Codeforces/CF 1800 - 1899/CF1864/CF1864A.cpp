#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> x >> y >> n;
    if (x + (n * (n - 1)) / 2 > y) {
        cout << "-1\n";
    }
    else {
        vector<int> v(n);
        v[0] = x;
        v[n - 1] = y;
        for (int i = 1; i + 1 < n; ++i) {
            v[n - i - 1] = v[n - i] - i;
        }
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
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