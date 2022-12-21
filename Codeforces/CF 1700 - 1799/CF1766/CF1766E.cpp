#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;
int dp[N][4][2][2];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, cur = 0;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> k;
        ++dp[i - 1][0][0][0];
        if (k == 0) {
            ans += 1LL * i * (n - i + 1);
            for (int j = 0; j < 4; ++j)
                for (int x = 0; x < 2; ++x)
                    for (int y = 0; y < 2; ++y)
                        dp[i][j][x][y] = dp[i - 1][j][x][y];
        }
        else if (k == 1)
            for (int j = 0; j < 4; ++j)
                for (int x = 0; x < 2; ++x)
                    for (int y = 0; y < 2; ++y) {
                        if (k & j)
                            dp[i][k][x][y] += dp[i - 1][j][x][y];
                        else if (x)
                            dp[i][j][x][y] += dp[i - 1][j][x][y];
                        else {
                            cur += dp[i - 1][j][x][y];
                            if (j == 0)
                                dp[i][k][x][y] += dp[i - 1][j][x][y];
                            else
                                dp[i][j][1][y] += dp[i - 1][j][x][y];
                        }
                    }
        else if (k == 2)
            for (int j = 0; j < 4; ++j)
                for (int x = 0; x < 2; ++x)
                    for (int y = 0; y < 2; ++y) {
                        if (k & j)
                            dp[i][k][x][y] += dp[i - 1][j][x][y];
                        else if (y)
                            dp[i][j][x][y] += dp[i - 1][j][x][y];
                        else {
                            cur += dp[i - 1][j][x][y];
                            if (j == 0)
                                dp[i][k][x][y] += dp[i - 1][j][x][y];
                            else
                                dp[i][j][x][1] += dp[i - 1][j][x][y];
                        }
                    }
        else
            for (int j = 0; j < 4; ++j)
                for (int x = 0; x < 2; ++x)
                    for (int y = 0; y < 2; ++y) {
                        if (j == 0)
                            cur += dp[i - 1][j][x][y];
                        dp[i][3][x][y] += dp[i - 1][j][x][y];
                    }
        // for (int j = 0; j < 4; ++j)
        //     for (int x = 0; x < 2; ++x)
        //         for (int y = 0; y < 2; ++y)
        //             if (dp[i][j][x][y] != 0) {
        //                 cout << i << j << x << y << ": " << dp[i][j][x][y] << endl;
        //             }
        ans += cur;
    }
    cout << ans;
    return 0;
}