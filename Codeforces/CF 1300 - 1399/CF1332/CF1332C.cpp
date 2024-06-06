#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> cnt(k);
    vector<vector<int>> f(k, vector<int>(26));
    string s, t(k, 'a');
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if ((i % k) * 2 < k) {
            ++f[i % k][s[i] - 'a'];
            ++cnt[i % k];
        }
        else {
            ++f[k - (i % k) - 1][s[i] - 'a'];
            ++cnt[k - (i % k) - 1];
        }
    }
    for (int i = 0; i * 2 < k; ++i) {
        int id = 0;
        for (int j = 1; j < 26; ++j) {
            if (f[i][j] > f[i][id]) {
                id = j;
            }
        }
        ans += cnt[i] - f[i][id];
    }
    cout << ans << "\n";
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