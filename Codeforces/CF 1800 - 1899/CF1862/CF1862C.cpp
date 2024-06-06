#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), w;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (v[0] != n) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < v[n - 1]; ++i) {
        w.push_back(n);
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < v[i] - v[i + 1]; ++j) {
            w.push_back(i + 1);
        }
    }
    if (v == w) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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