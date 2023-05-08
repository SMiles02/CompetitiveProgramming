#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1001;
int n, m, a[N][N], cur;
bitset<N> dn[N];
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

bool ok(int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < m && a[x][y] > 0 && !dn[x][y];
}

void dfs(int x, int y) {
    cur += a[x][y];
    dn[x][y] = 1;
    for (int i = 0; i < 4; ++i)
        if (ok(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
}

void solve() {
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            dn[i][j] = 0;
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] > 0 && !dn[i][j]) {
                cur = 0;
                dfs(i, j);
                ans = max(ans, cur);
            }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}