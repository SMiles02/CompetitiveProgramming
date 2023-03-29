#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m;
    cin >> m;
    vector<vector<int>> v(m);
    int ans[m];
    set<int> s;
    for (int i = 0; i < m; ++i) {
        int n, k;
        cin >> n;
        while (n--) {
            cin >> k;
            v[i].push_back(k);
        }
    }
    for (int i = m - 1; i >= 0; --i) {
        ans[i] = -1;
        for (auto j : v[i])
            if (s.count(j) == 0) {
                ans[i] = j;
                s.insert(j);
            }
        if (ans[i] == -1) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < m; ++i)
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