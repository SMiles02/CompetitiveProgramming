#include <bits/stdc++.h>
using namespace std;

const int N = 1001, INF = -1e9;
int n, m;
string s[N];

void solve() {
    int x, y, mx = 1e9;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    vector<vector<int>> v(n, vector<int>(m, INF)), ans1(n, vector<int>(m, INF)), ans2(n, vector<int>(m, INF)), ans(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        x = m;
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'B')
                x = min(x, j);
            if (x != m)
                v[i][j] = max(v[i][j], j - x);
        }
        x = 0;
        for (int j = m - 1; j >= 0; --j) {
            if (s[i][j] == 'B')
                x = max(x, j);
            if (x != 0)
                v[i][j] = max(v[i][j], x - j);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            ans1[i][j] = v[i][j];
        if (i > 0)
            for (int j = 0; j < m; ++j)
                ans1[i][j] = max(ans1[i][j], ans1[i - 1][j] + 1);
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j)
            ans2[i][j] = v[i][j];
        if (i < n - 1)
            for (int j = 0; j < m; ++j)
                ans2[i][j] = max(ans2[i][j], ans2[i + 1][j] + 1);
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            ans[i][j] = max(ans1[i][j], ans2[i][j]);
            if (ans[i][j] < mx) {
                mx = ans[i][j];
                x = i + 1;
                y = j + 1;
            }
        }
    cout << x << " " << y << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}