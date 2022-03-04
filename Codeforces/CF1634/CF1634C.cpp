#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1 || (n & 1) == 0) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j)
                cout << j * n + i + 1 << " ";
            cout << "\n";
        }
    }
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}