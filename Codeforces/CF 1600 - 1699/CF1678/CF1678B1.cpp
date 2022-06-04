#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v = {0, 1};
    string s;
    cin >> s;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1])
            v.push_back(0);
        ++v.back();
    }
    // 0: -1
    // 1: 0
    // 2: +1
    vector<vector<int>> dp(v.size(), vector<int>(3, 1e9));
    dp[0][1] = 0;
    for (int i = 1; i < v.size(); ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                if (v[i] + j + k - 2 >= 0 && (v[i] + j + k) % 2 == 0)
                    dp[i][k] = dp[i - 1][j] + (k != 1);
    
    cout << dp[v.size() - 1][1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}