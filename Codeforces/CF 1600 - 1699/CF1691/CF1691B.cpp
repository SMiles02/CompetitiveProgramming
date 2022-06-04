#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n;
    int ans[n + 1];
    set<int> s;
    map<int, vector<int>> m;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        m[k].push_back(i);
        s.insert(k);
    }
    for (int i : s) {
        if (m[i].size() == 1) {
            cout << "-1\n";
            return;
        }
        m[i].push_back(m[i][0]);
        for (int j = 1; j < m[i].size(); ++j)
            ans[m[i][j]] = m[i][j - 1];
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
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