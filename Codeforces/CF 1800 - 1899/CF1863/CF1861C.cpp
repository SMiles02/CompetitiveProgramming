#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
bitset<2> dp[N][2], source[N][2][2][2];

void solve() {
    int n, cur_len = 0;
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k] = 0;
                for (int x = 0; x < 2; ++x) {
                    for (int y = 0; y < 2; ++y) {
                        source[i][j][k][x][y] = 0;
                    }
                }
            }
        }
    }
    dp[0][0][1] = 1;
    for (int c = 0; c < n; ++c) {
        if (s[c] == '+') {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    if (dp[cur_len][i][j] == 0) {
                        continue;
                    }
                    for (int x = 0; x < 2; ++x) {
                        int y = 1 - (i > x || j == 0);
                        dp[cur_len + 1][x][y] = 1;
                        source[cur_len + 1][x][y][i][j] = 1;
                    }
                }
            }
            ++cur_len;
        }
        else if (s[c] == '-') {
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    dp[cur_len - 1][i][j] = 0;
                }
            }
            for (int x = 0; x < 2; ++x) {
                for (int y = 0; y < 2; ++y) {
                    for (int i = 0; i < 2; ++i) {
                        for (int j = 0; j < 2; ++j) {
                            if (dp[cur_len][x][y] == 1 && source[cur_len][x][y][i][j] == 1) {
                                dp[cur_len - 1][i][j] = 1;
                            }
                            source[cur_len][x][y][i][j] = 0;
                        }
                    }
                    dp[cur_len][x][y] = 0;
                }
            }
            --cur_len;
        }
        else {
            bool found = false;
            for (int x = 0; x < 2; ++x) {
                dp[cur_len][x][1 - (s[c] - '0')] = 0;
                if (dp[cur_len][x][(s[c] - '0')]) {
                    found = true;
                }
            }
            if (!found) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}