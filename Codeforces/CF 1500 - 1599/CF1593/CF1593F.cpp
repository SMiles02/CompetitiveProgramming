#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string s, ans = "";
    cin >> s;
    vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(n * 2 + 1, vector<vector<int>>(x, vector<int>(y, -1))));
    dp[0][n][0][0] = 0;
    for (int c = 0; c < n; ++c) {
        for (int i = 1; i < n * 2; ++i) {
            for (int j = 0; j < x; ++j) {
                for (int k = 0; k < y; ++k) {
                    if (dp[c][i + 1][j][k] != -1) {
                        dp[c + 1][i][(j * 10 + (s[c] - '0')) % x][k] = j;
                    }
                    if (dp[c][i - 1][j][k] != -1) {
                        dp[c + 1][i][j][(k * 10 + (s[c] - '0')) % y] = k + x;
                    }
                }
            }
        }
    }
    int m = 0, p = 0, q = 0;
    for (int i = 1; i < n * 2; ++i) {
        if (dp[n][i][0][0] != -1 && abs(i - n) < abs(m - n)) {
            m = i;
        }
    }

    if (m == 0) {
        cout << "-1\n";
        return;
    }
    for (int i = n; i > 0; --i) {
        if (dp[i][m][p][q] < x) {
            ans += 'R';
            p = dp[i][m][p][q];
            ++m;
        }
        else {
            ans += 'B';
            q = dp[i][m][p][q] - x;
            --m;
        }
    }
    reverse(ans.begin(), ans.end());
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