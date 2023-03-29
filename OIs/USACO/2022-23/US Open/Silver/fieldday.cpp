#include <bits/stdc++.h>
using namespace std;

const int C = 1 << 9;
int dp[C][C];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, c;
    cin >> c >> n;
    int a[n][2];
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < C; ++j)
            dp[i][j] = -100;
    for (int i = 0; i < n; ++i) {
        int x = 0, y = 0;
        string s;
        cin >> s;
        for (int j = 0; j < min(9, c); ++j)
            x += (1 << j) * (s[j] == 'H');
        for (int j = 9; j < c; ++j)
            y += (1 << (j - 9)) * (s[j] == 'H');
        for (int j = 0; j < C; ++j)
            dp[j][y] = max(dp[j][y], __builtin_popcount(x ^ j));
        a[i][0] = x;
        a[i][1] = y;
    }
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = 0; j < C; ++j)
            ans = max(ans, dp[a[i][0]][j] + __builtin_popcount(a[i][1] ^ j));
        cout << ans << "\n";
    }
    return 0;
}