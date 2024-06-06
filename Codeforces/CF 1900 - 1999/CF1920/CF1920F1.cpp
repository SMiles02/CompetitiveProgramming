#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<int> dx = {0, 0, -1, 1, -1, -1, 1, 1};
vector<int> dy = {-1, 1, 0, 0, -1, 1, -1, 1};

bool ok(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int qr, lx, ly;
    cin >> n >> m >> qr;
    vector<string> s(n);
    vector<vector<int>> dv(n, vector<int>(m, INF));
    vector<vector<bool>> path(n, vector<bool>(m)), cv(n, vector<bool>(m));
    queue<array<int, 2>> q;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'v') {
                q.push({i, j});
                dv[i][j] = 0;
            }
            else if (s[i][j] == '#') {
                lx = i;
                ly = j;
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (ok(nx, ny) && dv[nx][ny] == INF) {
                dv[nx][ny] = dv[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    while (qr--) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        int l = 0, r = dv[a][b], mid;
        while (l < r) {
            mid = l + (r - l) / 2 + 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    path[i][j] = false;
                    cv[i][j] = false;
                }
            }
            path[a][b] = true;
            q.push({a, b});
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (ok(nx, ny) && dv[nx][ny] >= mid && !path[nx][ny] && s[nx][ny] != '#') {
                        path[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            bool works = true;
            cv[lx][ly] = true;
            q.push({lx, ly});
            while (!q.empty()) {
                auto [x, y] = q.front();
                if (x == 0 || y == 0 || x == n - 1 || y == m - 1) {
                    works = false;
                }
                q.pop();
                for (int i = 0; i < 8; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (ok(nx, ny) && !path[nx][ny] && !cv[nx][ny]) {
                        cv[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            if (works) {
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }
        cout << l << "\n";
    }
    return 0;
}