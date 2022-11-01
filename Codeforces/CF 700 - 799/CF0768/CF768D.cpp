#include <bits/stdc++.h>
using namespace std;

const int E = 1e-7, N = 10002, K = 1002;
double dp[N][K];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k, q, p, l, r, m;
    cin >> k >> q;
    dp[0][0] = 1;
    for (int i = 0; i + 1 < N; ++i)
        for (int j = 0; j <= k; ++j) {
            dp[i + 1][j] += dp[i][j] * (((double) j) / k);
            dp[i + 1][j + 1] += dp[i][j] * (((double) k - j) / k);
        }
    while (q--) {
        cin >> p;
        l = 1;
        r = N - 1;
        while (l < r) {
            m = l + (r - l) / 2;
            if (((double)p - E) / 2000 <= dp[m][k])
                r = m;
            else
                l = m + 1;
        }
        cout << l << "\n";
    }
    return 0;
}