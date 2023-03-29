#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5, INF = 1e6;
const long long C = 1e12;
array<int, 2> dp[N][3];

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = {dp[i][1][0] + 1, dp[i][1][1]};
            dp[i + 1][2] = {dp[i][2][0] + 1, dp[i][2][1] + 1};
        }
        else {
            dp[i + 1][0] = {dp[i][0][0] + 1, dp[i][0][1] + 1};
            dp[i + 1][1] = min(dp[i][0], {dp[i][1][0] + 1, dp[i][1][1] + 1});
            dp[i + 1][2] = min(dp[i][1], dp[i][2]);
        }
    }
    array<int, 2> ans = min({dp[n][0], dp[n][1], dp[n][2]});
    cout << C * ans[0] + ans[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    dp[0][0] = {0, 0};
    dp[0][1] = {INF, INF};
    dp[0][2] = {INF, INF};
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}