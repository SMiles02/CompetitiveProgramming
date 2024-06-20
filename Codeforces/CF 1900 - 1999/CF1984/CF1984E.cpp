#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 2;
int dp[N][2][2];
vector<int> e[N];

void dfs(int c, int p) {
    dp[c][0][0] = 0;
    dp[c][0][1] = 1;
    dp[c][1][0] = dp[c][1][1] = 0;
    if (e[c].size() == 1) {
        dp[c][1][0] = 1;
    }
    int max_diff_0 = 0, max_diff_1 = 0;
    for (int i : e[c]) {
        if (i == p) {
            continue;
        }
        dfs(i, c);
        dp[c][1][0] = dp[c][0][0] += max(dp[i][0][0], dp[i][0][1]);
        dp[c][1][1] = dp[c][0][1] += dp[i][0][0];
        max_diff_0 = max(max_diff_0, max(dp[i][1][0], dp[i][1][1]) - max(dp[i][0][0], dp[i][0][1]));
        max_diff_1 = max(max_diff_1, dp[i][1][0] - dp[i][0][0]);
    }
    dp[c][1][0] = dp[c][0][0] + max(max_diff_0, int(e[c].size() == 1));
    dp[c][1][1] = dp[c][0][1] + max_diff_1;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
    }
    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    cout << max(dp[1][1][0], dp[1][1][1]) << "\n";
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