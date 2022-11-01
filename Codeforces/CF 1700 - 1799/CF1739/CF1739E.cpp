#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    vector<string> s(2);
    vector<vector<int>> dp(2, vector<int>(n + 2, 1e9));
    for (int i = 0; i < 2; ++i) {
        cin >> s[i];
        s[i] += "00";
        for (auto j : s[i])
            cnt += (j == '1');
    }
    dp[0][0] = 0;
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < 2; ++x) {
            if (s[1 - x][y] == '0')
                dp[x][y + 1] = min(dp[x][y + 1], dp[x][y]);
            else if (s[x][y + 1] == '0')
                dp[1 - x][y + 2] = min(dp[1 - x][y + 2], dp[x][y]);
            else {
                dp[x][y + 1] = min(dp[x][y + 1], dp[x][y] + 1);
                dp[1 - x][y + 2] = min(dp[1 - x][y + 2], dp[x][y] + 1);
            }
        }
    cout << cnt - min({dp[0][n], dp[0][n + 1], dp[1][n], dp[1][n + 1]});
    return 0;
}