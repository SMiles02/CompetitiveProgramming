#include <bits/stdc++.h>
using namespace std;

const int N = 501, INF = 1e9;
int dist[N][N];
vector<array<int, 2>> e[N];

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
    vector<int> special(s);
    for (int i = 0; i < s; ++i)
        cin >> special[i];
    for (int a = 0; a < s; ++a)
        for (int b = a + 1; b < s; ++b)
            for (int c = 0; c < s; ++c)
                if (c != a && c != b)
                    for (int d = c + 1; d < s; ++d)
                        if (d != a && d != b)
                            ans = min(ans, dist[special[a]][special[b]] + dist[special[c]][special[d]]);
    cout << ans;
    return 0;
}