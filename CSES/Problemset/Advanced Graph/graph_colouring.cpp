#include <bits/stdc++.h>
using namespace std;

const int N = 16;
int dp[1 << N];
bitset<N> e[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        e[x][y] = e[y][x] = 1;
    }
    for (int i = 1; i < (1 << n); ++i) {
        dp[i] = 1;
        for (int x = 0; x < n; ++x) {
            if (i & (1 << x)) {
                for (int y = x + 1; y < n; ++y) {
                    if (i & (1 << y) && e[x][y]) {
                        dp[i] = __builtin_popcount(i);
                    }
                }
            }
        }
    }
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = i - 1; j > 0; j = (j - 1) & i) {
            if (dp[j] == 1) {
                dp[i] = min(dp[i], dp[i ^ j] + 1);
            }
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
    vector<int> ans(n, dp[(1 << n) - 1]);
    int i = (1 << n) - 1;
    while (dp[i] > 1) {
        for (int j = i - 1; j > 0; j = (j - 1) & i) {
            if (dp[j] == 1 && dp[i ^ j] == dp[i] - 1) {
                for (int k = 0; k < n; ++k) {
                    if (j & (1 << k)) {
                        ans[k] = dp[(1 << n) - 1] - dp[i] + 1;
                    }
                }
                i ^= j;
                break;
            }
        }
    }
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}