#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 101;
int a[N][N], dp[N][N];

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, ans = 0;
    cin >> n;
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j)
            cin >> a[i][j];
        ok &= (a[i][i] != 2);
    }
    dp[1][0] = 2 * ok;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j + 1 < i; ++j) {
            dp[i][j] = dp[i - 1][j];
            dp[i][i - 1] = add(dp[i][i - 1], dp[i - 1][j]);
        }
        for (int j = 1; j <= i; ++j) {
            if (a[j][i] == 1)
                for (int k = j; k <= i; ++k)
                    dp[i][k] = 0;
            if (a[j][i] == 2)
                for (int k = 0; k < j; ++k)
                    dp[i][k] = 0;
        }
    }
    for (int j = 0; j <= n; ++j)
        ans = add(ans, dp[n][j]);
    cout << ans;
    return 0;
}