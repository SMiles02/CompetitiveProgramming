#include <bits/stdc++.h>
using namespace std;

const int N = 10, M = 1001, MOD = 1e9 + 7;
int dp[M][1 << N];

int add(int x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> acceptable_vertical;
    for (int i = 0; i < (1 << n); ++i) {
        bool ok = true;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                if (j + 1 == n || (j + 1 < n && (i & (1 << (j + 1))) == 0)) {
                    ok = false;
                }
                ++j;
            }
        }
        if (ok) {
            acceptable_vertical.push_back(i);
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            for (int k : acceptable_vertical) {
                if ((j & k) == 0) {
                    dp[i + 1][((1 << n) - 1) ^ j ^ k] = add(dp[i + 1][((1 << n) - 1) ^ j ^ k], dp[i][j]);
                }
            }
        }
    }
    cout << dp[m][0] << "\n";
    return 0;
}