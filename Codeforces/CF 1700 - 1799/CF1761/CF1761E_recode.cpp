#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<bool>> e(n + 1, vector<bool>(n + 1));
    vector<bool> dn(n + 1);
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; ++j)
            e[i][j] = s[j - 1] - '1';
    }
    vector<vector<int>> v;
    for (int i = 1; i <= n; ++i)
        if (!dn[i]) {
            vector<int> w = {i};
            for (int j = i + 1; j <= n; ++j)
                
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