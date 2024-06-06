#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 1, A = 26 * 26 + 1, INF = 1e9;
vector<array<int, 2>> e[N + A];
int d[A][N + A];

void add_edge(int x, int y, int xy, int yx) {
    e[x].push_back({y, xy});
    e[y].push_back({x, yx});
}

void bfs(int i, int s) {
    for (int j = 0; j < N + A; ++j) {
        d[i][j] = INF;
    }
    d[i][s] = 0;
    deque<array<int, 2>> q;
    q.push_back({s, 0});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop_front();
        if (d[i][x] < y) {
            continue;
        }
        for (auto& [t, w] : e[x]) {
            if (y + w < d[i][t]) {
                d[i][t] = y + w;
                if (w == 0) {
                    q.push_front({t, d[i][t]});
                }
                else {
                    q.push_back({t, d[i][t]});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size(), q;
    cin >> q;
    for (int i = 0; i + 1 < n; ++i) {
        if (i > 0) {
            add_edge(i - 1, i, 1, 1);
        }
        add_edge(i, n - 1 + (s[i] - 'a') * 26 + (s[i + 1] - 'a'), 1, 0);
    }
    for (int i = 0; i < 26 * 26; ++i) {
        bfs(i, n - 1 + i);
    }
    while (q--) {
        int x, y, ans;
        cin >> x >> y;
        --x;
        --y;
        ans = abs(x - y);
        for (int i = 0; i < 26 * 26; ++i) {
            ans = min(ans, d[i][x] + d[i][y] + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}