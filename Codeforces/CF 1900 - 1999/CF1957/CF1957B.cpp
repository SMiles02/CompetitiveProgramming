#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << k << "\n";
    }
    else {
        cout << (1 << __lg(k)) - 1 << " " << k - (1 << __lg(k)) + 1 << " ";
        for (int i = 2; i < n; ++i) {
            cout << "0 ";
        }
        cout << "\n";
    }
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