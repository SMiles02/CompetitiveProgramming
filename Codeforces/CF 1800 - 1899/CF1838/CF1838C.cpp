#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> v(2);
    for (int i = 0; i < n; ++i) {
        vector<int> a(m);
        for (int j = 0; j < m; ++j)
            a[j] = i * m + j + 1;
        v[i < n / 2].push_back(a);
    }
    for (int i = 0; i < n; ++i) {
        for (auto j : v[i & 1][i / 2])
            cout << j << " ";
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