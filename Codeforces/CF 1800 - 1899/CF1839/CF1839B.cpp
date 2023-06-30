#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        sort(v[i].rbegin(), v[i].rend());
        for (int j = 0; j < min(i, (int)v[i].size()); ++j)
            ans += v[i][j];
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}