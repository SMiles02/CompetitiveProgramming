#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 51;
int dp[60][N][N];

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, sum = 0;
    long long k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dp[0][i][j];
        }
    }
    for (int p = 1; p < 60; ++p) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int x = 0; x < n; ++x) {
                    dp[p][i][j] = add(dp[p][i][j], mul(dp[p - 1][i][x], dp[p - 1][x][j]));
                }
            }
        }
    }
    vector<vector<int>> ans(2, vector<int>(n, 1));
    for (int p = 0; p < 60; ++p) {
        if (((1LL << p) & k) == 0) {
            continue;
        }
        for (int i = 0; i < n; ++i) {
            ans[1][i] = 0;
            for (int j = 0; j < n; ++j) {
                ans[1][i] = add(ans[1][i], mul(ans[0][j], dp[p][j][i]));
            }
        }
        swap(ans[0], ans[1]);
    }
    for (int i = 0; i < n; ++i) {
        sum = add(sum, ans[0][i]);
    }
    cout << sum;
    return 0;
}