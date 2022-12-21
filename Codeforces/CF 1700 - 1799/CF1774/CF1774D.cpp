#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, s = 0, k, cur = 0, x, y;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    vector<int> row_count(n);
    vector<array<int, 3>> ans;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j];
            s += v[i][j];
            row_count[i] += v[i][j];
        }
    if (s % n) {
        cout << "-1\n";
        return;
    }
    k = s / n;
    for (int j = 0; j < m; ++j) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> to_add;
        priority_queue<array<int, 2>> to_rem;
        for (int i = 0; i < n; ++i) {
            if (v[i][j] == 0 && row_count[i] < k)
                to_add.push({row_count[i], i});
            if (v[i][j] == 1 && row_count[i] > k)
                to_rem.push({row_count[i], i});
        }
        while (!to_add.empty() && !to_rem.empty()) {
            x = to_rem.top()[1];
            y = to_add.top()[1];
            to_rem.pop();
            to_add.pop();
            --row_count[x];
            ++row_count[y];
            ans.push_back({x + 1, y + 1, j + 1});
        }
    }
    cout << ans.size() << "\n";
    for (auto i : ans) {
        for (auto j : i)
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