// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 3001;
int d[N][N], ans[N], cur[N];
vector<int> e[N];

void dfs(int c, int p, int h, int src) {
    d[src][c] = h;
    for (int i : e[c])
        if (i != p)
            dfs(i, c, h + 1, src);
}

void solve() {
    int n, x, y, mx = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i)
        dfs(i, 0, 0, i);
    for (int i = 1; i <= n; ++i)
        mx = max(mx, d[1][i]);
    for (int i = 1; i <= n; ++i)
        ans[i] = mx;
    for (int i = 1; i <= n; ++i) {
        mx = 0;
        for (int j = 1; j <= n; ++j) {
            mx = max(mx, min(d[1][j], d[i][j] + 1));
            cur[j] = 0;
        }
        cur[1] = mx;
        for (int j = 1; j <= n; ++j)
            if (d[1][j] > d[i][j])
                cur[d[1][j] - d[i][j]] = max(cur[d[1][j] - d[i][j]], d[1][j]);
        for (int j = 1; j <= n; ++j) {
            cur[j] = max(cur[j - 1], cur[j]);
            ans[j] = min(ans[j], cur[j]);
        }
        // cerr << i << "\n";
        // for (int j = 1; j <= n; ++j)
        //     cerr << cur[j] << " ";
        // cerr << "\n";
    }
    // cerr << "\n";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}