#include <bits/stdc++.h>
using namespace std;

const int M = 2e5 + 1;
int a[2][M], b[2][M], c[2][M];

void solve() {
    int m, ans = 2e9, cur;
    cin >> m;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    a[0][0] = -1;
    for (int i = 0; i < 2; ++i) {
        b[i][m - 1] = m - 1;
        cur = a[i][m - 1];
        for (int j = m - 2; j >= 0; --j) {
            if (a[i][j] + m - 1 - j > cur) {
                cur = a[i][j] + m - 1 - j;
                b[i][j] = j;
            }
            else
                b[i][j] = b[i][j + 1];
        }
    }
    for (int i = 0; i < 2; ++i) {
        c[i][m - 1] = m - 1;
        cur = a[i][m - 1];
        for (int j = m - 2; j >= 0; --j) {
            if (a[i][j] - m + 1 + j > cur) {
                cur = a[i][j] - m + 1 + j;
                c[i][j] = j;
            }
            else
                c[i][j] = c[i][j + 1];
        }
    }
    cur = -1;
    for (int j = 0; j < m; ++j) {
        if (j & 1) {
            ans = min(ans, max({cur + (m - j) * 2, a[1][b[1][j]] + m - b[1][j] + m - j, a[0][c[0][j]] + c[0][j] - j + 1}));
            cur = max(cur, a[1][j]) + 1;
            cur = max(cur, a[0][j]) + 1;
        }
        else {
            ans = min(ans, max({cur + (m - j) * 2, a[0][b[0][j]] + m - b[0][j] + m - j, a[1][c[1][j]] + c[1][j] - j + 1}));
            cur = max(cur, a[0][j]) + 1;
            cur = max(cur, a[1][j]) + 1;
        }
    }
    cout << min(ans, cur) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}