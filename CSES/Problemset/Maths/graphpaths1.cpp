#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

const int N = 100, L = 30;
int up[L][N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    while (m--) {
        int x, y;
        cin >> x >> y;
        ++up[0][x][y];
    }
    for (int p = 1; p < L; ++p)
        for (int x = 1; x <= n; ++x)
            for (int y = 1; y <= n; ++y)
                for (int z = 1; z <= n; ++z)
                    up[p][x][y] = add(up[p][x][y], mul(up[p - 1][x][z], up[p - 1][z][y]));
    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int p = 0; p < L; ++p)
        if ((1 << p) & k) {
            vector<int> new_dp(n + 1);
            for (int x = 1; x <= n; ++x)
                for (int y = 1; y <= n; ++y)
                    new_dp[y] = add(new_dp[y], mul(dp[x], up[p][x][y]));
            swap(dp, new_dp);
        }
    cout << dp[n];
    return 0;
}