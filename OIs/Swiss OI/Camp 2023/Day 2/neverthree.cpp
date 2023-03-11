#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 5001;
int dp[N][N][2], p[N][N][2], q[N][N][2];

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int sub(int a, int b) { return add(a, MOD - b); }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < 2; ++i)
        dp[0][0][i] = p[0][0][i] = q[0][0][i] = 1;
    for (int k = 1; k <= x + y; ++k)
        for (int i = 0; i <= x && i <= k; ++i)
            if (k - i <= y) {
                int j = k - i;
                if (i > 0)
                    dp[i][j][0] = p[i - 1][j][1];
                if (i - 3 >= 0)
                    dp[i][j][0] = sub(dp[i][j][0], dp[i - 3][j][1]);
                if (j > 0)
                    dp[i][j][1] = q[i][j - 1][0];
                if (j - 3 >= 0)
                    dp[i][j][1] = sub(dp[i][j][1], dp[i][j - 3][0]);
                if (i > 0) {
                    p[i][j][0] = add(dp[i][j][0], p[i - 1][j][0]);
                    p[i][j][1] = add(dp[i][j][1], p[i - 1][j][1]);
                }
                else {
                    p[i][j][0] = dp[i][j][0];
                    p[i][j][1] = dp[i][j][1];
                }
                if (j > 0) {
                    q[i][j][0] = add(dp[i][j][0], q[i][j - 1][0]);
                    q[i][j][1] = add(dp[i][j][1], q[i][j - 1][1]);
                }
                else {
                    q[i][j][0] = dp[i][j][0];
                    q[i][j][1] = dp[i][j][1];
                }
            }
    // for (int i = 0; i <= x; ++i) {
    //     for (int j = 0; j <= y; ++j)
    //         cout << dp[i][j][0] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    // for (int i = 0; i <= x; ++i) {
    //     for (int j = 0; j <= y; ++j)
    //         cout << dp[i][j][1] << " ";
    //     cout << "\n";
    // }
    // cout << "\n";
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j)
            cout << dp[i][j][0] << ":" << dp[i][j][1] << " ";
        cout << "\n";
    }
    cout << add(dp[x][y][0], dp[x][y][1]);
    return 0;
}