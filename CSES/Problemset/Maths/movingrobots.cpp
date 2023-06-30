#include <bits/stdc++.h>
using namespace std;

const int N = 8, K = 101;
int cnt[N][N];
double dp[N * N][K][N][N];
vector<int> dx = {-1, 0, 0, 1};
vector<int> dy = {0, -1, 1, 0};

bool ok(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    cin >> k;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            dp[i * N + j][0][i][j] = 1;
            for (int z = 0; z < 4; ++z)
                cnt[i][j] += ok(i + dx[z], j + dy[z]);
        }
    for (int i = 0; i < N * N; ++i)
        for (int j = 1; j <= k; ++j)
            for (int x = 0; x < N; ++x)
                for (int y = 0; y < N; ++y)
                    for (int z = 0; z < 4; ++z)
                        if (ok(x + dx[z], y + dy[z]))
                            dp[i][j][x][y] += dp[i][j - 1][x + dx[z]][y + dy[z]] / cnt[x + dx[z]][y + dy[z]];
    double ans = 0;
    for (int x = 0; x < N; ++x)
        for (int y = 0; y < N; ++y) {
            double cur = 1;
            for (int i = 0; i < N * N; ++i)
                cur *= 1 - dp[i][k][x][y];
            ans += cur;
        }
    cout << fixed << setprecision(6) << ans;
    return 0;
}