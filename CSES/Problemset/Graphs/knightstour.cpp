#include <bits/stdc++.h>
using namespace std;

const int N = 8;
const vector<int> dx = {-1, -1, 1, 1, -2, -2, 2, 2};
const vector<int> dy = {-2, 2, -2, 2, -1, 1, -1, 1};
int g[N + 1][N + 1], options[N + 1][N + 1];

bool ok(int x, int y) {
    return 1 <= min(x, y) && max(x, y) <= N && g[x][y] == 0;
}

bool solve(int x, int y) {
    if (g[x][y] == N * N) {
        return true;
    }
    vector<array<int, 3>> next_move;
    for (int t = 0; t < 8; ++t) {
        int tx = x + dx[t], ty = y + dy[t];
        if (ok(tx, ty)) {
            next_move.push_back({options[tx][ty], tx, ty});
        }
    }
    sort(next_move.begin(), next_move.end());
    for (auto [z, i, j] : next_move) {
        g[i][j] = g[x][y] + 1;
        for (int t = 0; t < 8; ++t) {
            int tx = i + dx[t], ty = j + dy[t];
            if (ok(tx, ty)) {
                --options[tx][ty];
            }
        }
        if (solve(i, j)) {
            return true;
        }
        g[i][j] = 0;
        for (int t = 0; t < 8; ++t) {
            int tx = i + dx[t], ty = j + dy[t];
            if (ok(tx, ty)) {
                ++options[tx][ty];
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, y;
    cin >> y >> x;
    g[x][y] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            for (int k = 0; k < 8; ++k) {
                int tx = i + dx[k], ty = j + dy[k];
                options[i][j] += ok(tx, ty);
            }
        }
    }
    solve(x, y);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}