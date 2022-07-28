#include <bits/stdc++.h>
using namespace std;

const int N = 501, INF = 1e9;
int dist[N][N];
vector<array<int, 2>> e[N];
bitset<N> is_special;

bool all_unique(array<int, 4> a) {
    for (int i = 1; i < 4; ++i)
        for (int j = 0; j < i; ++j)
            if (a[i] == a[j])
                return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, s, x, y, z, ans = INF;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            dist[i][j] = INF;
        dist[i][i] = 0;
    }
    while (m--) {
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
        dist[x][y] = dist[y][x] = z;
    }
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= n; ++i)
            for (int k = 1; k <= n; ++k)
                dist[i][k] = min(dist[i][k], dist[i][j] + dist[j][k]);
    vector<vector<array<int, 2>>> v(n + 1, vector<array<int, 2>>(n, {INF, 420}));
    for (int i = 0; i < s; ++i) {
        cin >> x;
        is_special[x] = 1;
    }
    for (int i = 1; i <= n; ++i)
        if (is_special[i]) {
            for (int j = 1; j <= n; ++j)
                if (is_special[j] && i != j)
                    v[i][j] = {dist[i][j], j};
            sort(v[i].begin(), v[i].end());
        }
    for (int a = 1; a <= n; ++a)
        if (is_special[a])
            for (int b = a + 1; b <= n; ++b)
                if (is_special[b])
                    for (int c = 0; c < 3; ++c)
                        for (int d = 0; d < 3; ++d)
                            if (all_unique({a, b, v[a][c][1], v[b][d][1]}))
                                ans = min(ans, v[a][c][0] + v[b][d][0]);
    cout << ans;
    return 0;
}