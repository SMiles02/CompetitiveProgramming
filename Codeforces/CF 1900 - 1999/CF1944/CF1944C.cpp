#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cnt = 0;
    cin >> n;
    vector<int> f(n + 2);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        ++f[k];
    }
    for (int i = 0; i < n + 2; ++i) {
        if (f[i] == 0) {
            cout << i << "\n";
            return;
        }
        if (f[i] == 1) {
            ++cnt;
            if (cnt > 1) {
                cout << i << "\n";
                return;
            }
        }
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