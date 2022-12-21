#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j)
            if (s[j] == '1')
                ans[j].push_back(i);
        ans[i].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i].size() << " ";
        for (int j : ans[i])
            cout << j + 1 << " ";
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