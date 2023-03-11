#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

bool ok(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, p, x, y, k, s;
    cin >> t;
    cin >> n >> m >> p;
    cin >> x >> y >> k >> s;
    k &= (1 << s) - 1;
    --x;
    --y;
    int a[n][m], f[p][2];
    for (int i = 0; i < p; ++i) {
        cin >> f[i][0] >> f[i][1];
        --f[i][0];
        --f[i][1];
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            a[i][j] &= (1 << s) - 1;
            a[i][j] ^= (1 << s) - 1;
        }
    if (t == 1) {
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans += (!(i == x && j == y) && a[i][j] == k);
        cout << ans;
    }
    else {
        vector<vector<int>> d(n, vector<int>(m, INF));
        d[x][y] = 0;
        queue<array<int, 2>> q;
        q.push({x, y});
        while (!q.empty()) {
            int i = q.front()[0], j = q.front()[1];
            q.pop();
            for (int w = 0; w < 4; ++w)
                if (ok(i + dx[w], j + dy[w]) && d[i + dx[w]][j + dy[w]] == INF && a[i + dx[w]][j + dy[w]] == k) {
                    d[i + dx[w]][j + dy[w]] = d[i][j] + 1;
                    q.push({i + dx[w], j + dy[w]});
                }
        }
        int ans = INF, cnt = 0;
        for (int i = 0; i < p; ++i)
            if (ok(f[i][0], f[i][1])) {
                if (d[f[i][0]][f[i][1]] < ans) {
                    ans = d[f[i][0]][f[i][1]];
                    cnt = 1;
                }
                else if (d[f[i][0]][f[i][1]] == ans)
                    ++cnt;
            }
        cout << ans << " " << cnt;
    }
    return 0;
}