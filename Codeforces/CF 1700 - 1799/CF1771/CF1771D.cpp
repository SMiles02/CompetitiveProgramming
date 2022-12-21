#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 1;
int nx[N][N], ans[N][N];
vector<int> e[N];
vector<array<int, 2>> d[N];

void dfs(int c, int p, int r, int x) {
    if (c != r) {
        nx[r][c] = p;
        if (r < c)
            d[x].push_back({r, c});
    }
    for (int i : e[c])
        if (i != p)
            dfs(i, c, r, x + 1);
}

void set_ans(int x, int y, int k) {
    if (x > y)
        swap(x, y);
    ans[x][y] = max(ans[x][y], k);
}

void solve() {
    int n, x, y, final_ans = 1;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        d[i].clear();
        for (int j = 1; j <= n; ++j)
            ans[i][j] = 0;
    }
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        dfs(i, 0, i, 0);
    for (int i = n; i >= 1; --i)
        for (auto j : d[i]) {
            x = j[0];
            y = j[1];
            set_ans(x, nx[x][y], ans[x][y]);
            set_ans(y, nx[y][x], ans[x][y]);
            if (s[x - 1] == s[y - 1])
                ans[x][y] += 2;
            if (i != 1)
                set_ans(nx[x][y], nx[y][x], ans[x][y]);
            final_ans = max(final_ans, ans[x][y] + (i != 1));
        }
    cout << final_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}