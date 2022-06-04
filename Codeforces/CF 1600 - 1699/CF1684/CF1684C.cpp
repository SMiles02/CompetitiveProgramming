#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        vector<array<int, 2>> v(m);
        for (int j = 0; j < m; ++j)
            v[j] = {a[i][j], j};
        sort(v.begin(), v.end());
        for (int j = 1; j < m; ++j) {
            if (v[j - 1][1] - v[j][1] > r - l) {
                l = v[j][1];
                r = v[j - 1][1];
            }
            v[j][1] = max(v[j - 1][1], v[j][1]);
        }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        swap(a[i][l], a[i][r]);
        for (int j = 1; j < m; ++j)
            if (a[i][j - 1] > a[i][j])
                ok = false;
    }
    if (ok)
        cout << l + 1 << " " << r + 1 << "\n";
    else
        cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}