#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
const vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
int n, ans[N][N];

bool ok(int x, int y) {
    return 0 <= min(x, y) && max(x, y) < n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    queue<array<int, 2>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto &[x, y] = q.front();
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int tx = x + dx[i], ty = y + dy[i];
            if (ok(tx, ty) && ans[tx][ty] == 0 && max(tx, ty) > 0) {
                ans[tx][ty] = ans[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}