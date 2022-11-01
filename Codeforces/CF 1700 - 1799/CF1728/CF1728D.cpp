#include <bits/stdc++.h>
using namespace std;

const int N = 2002;
int dp[N][N];

void solve() {
    int n, cur;
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1])
            dp[i][i + 1] = 1;
        else
            dp[i][i + 1] = 2;
    }
    for (int j = 0; j < n; ++j)
        for (int i = j - 3; i >= 0; i -= 2) {
            dp[i][j] = 0;
            // A: i
            cur = 2;
            // B: i + 1
            if (dp[i + 2][j] == 0)
                cur = 0;
            else if (dp[i + 2][j] == 1) {
                if (s[i] > s[i + 1])
                    cur = 0;
                else if (s[i] == s[i + 1])
                    cur = min(cur, 1);
            }
            // B: j
            if (dp[i + 1][j - 1] == 0)
                cur = 0;
            else if (dp[i + 1][j - 1] == 1) {
                if (s[i] > s[j])
                    cur = 0;
                else if (s[i] == s[j])
                    cur = min(cur, 1);
            }
            dp[i][j] = max(dp[i][j], cur);
            // A: j
            cur = 2;
            // B: i
            if (dp[i + 1][j - 1] == 0)
                cur = 0;
            else if (dp[i + 1][j - 1] == 1) {
                if (s[j] > s[i])
                    cur = 0;
                else if (s[j] == s[i])
                    cur = min(cur, 1);
            }
            // B: j - 1
            if (dp[i][j - 2] == 0)
                cur = 0;
            else if (dp[i][j - 2] == 1) {
                if (s[j] > s[j - 1])
                    cur = 0;
                else if (s[j] == s[j - 1])
                    cur = min(cur, 1);
            }
            dp[i][j] = max(dp[i][j], cur);
        }
    if (dp[0][n - 1] == 2)
        cout << "Alice\n";
    else if (dp[0][n - 1] == 1)
        cout << "Draw\n";
    else
        cout << "Bob\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}