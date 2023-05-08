#include <bits/stdc++.h>
using namespace std;

const int N = 2023;
int n, timer, tin[N], low[N];
bitset<N> e[N], done, is_ap;

void dfs_ap(int c, int p) {
    // cout << c << " " << p << "\n";
    done[c] = 1;
    tin[c] = low[c] = timer++;
    int children = 0;
    for (int i = 1; i <= n; ++i)
        if (e[c][i] && i != p) {
            if (done[i])
                low[c] = min(low[c], tin[i]);
            else {
                dfs_ap(i, c);
                low[c] = min(low[c], low[i]);
                if (tin[c] <= low[i] && p != 0)
                    is_ap[c] = 1;
                ++children;
            }
        }
    if (p == 0 && children > 1)
        is_ap[c] = 1;
}

void find_articulation_points() {
    timer = 0;
    for (int i = 1; i <= n; ++i) {
        done[i] = 0;
        is_ap[i] = 0;
    }
    for (int i = 1; i <= n; ++i)
        if (!done[i])
            dfs_ap(i, 0);
    for (int i = 1; i <= n; ++i)
        if (is_ap[i])
            cout << i << " ";
    cout << "\n";
}

void solve() {
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            e[i][j] = 0;
    while (m--) {
        int x, y;
        cin >> x >> y;
        e[x][y] = e[y][x] = 1;
    }
    find_articulation_points();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}