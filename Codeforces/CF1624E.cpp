#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, cur;
    cin >> n >> m;
    vector<vector<array<int, 3>>> v(10, vector<array<int, 3>>(10));
    vector<vector<vector<array<int, 3>>>> w(10, vector<vector<array<int, 3>>>(10, vector<array<int, 3>>(10)));
    string s;
    for (int j = 1; j <= n; ++j) {
        cin >> s;
        for (int i = 1; i < m; ++i)
            v[s[i - 1] - '0'][s[i] - '0'] = {i, i + 1, j};
        for (int i = 2; i < m; ++i)
            w[s[i - 2] - '0'][s[i - 1] - '0'][s[i] - '0'] = {i - 1, i + 1, j};
    }
    cin >> s;
    vector<bool> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i < m; ++i)
        if ((dp[i - 1] && v[s[i - 1] - '0'][s[i] - '0'][0]) || (i > 1 && dp[i - 2] && w[s[i - 2] - '0'][s[i - 1] - '0'][s[i] - '0'][0]))
            dp[i + 1] = 1;
    if (!dp[m]) {
        cout << "-1\n";
        return;
    }
    vector<array<int, 3>> ans;
    cur = m;
    while (cur > 0) {
        if (dp[cur - 2] && v[s[cur - 2] - '0'][s[cur - 1] - '0'][0]) {
            ans.push_back(v[s[cur - 2] - '0'][s[cur - 1] - '0']);
            cur -= 2;
        }
        else {
            ans.push_back(w[s[cur - 3] - '0'][s[cur - 2] - '0'][s[cur - 1] - '0']);
            cur -= 3;
        }
    }
    cout << ans.size() << "\n";
    while (!ans.empty()) {
        cout << ans.back()[0] << " " << ans.back()[1] << " " << ans.back()[2] << "\n";
        ans.pop_back();
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