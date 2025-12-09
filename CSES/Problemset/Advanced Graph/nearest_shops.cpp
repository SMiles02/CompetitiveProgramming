#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
array<int, 2> d[N][2];
vector<int> e[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        d[i][0] = d[i][1] = {-1, -1};
    }
    queue<array<int, 2>> q;
    while (k--) {
        int x;
        cin >> x;
        d[x][0] = {0, x};
        q.push({x, 0});
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i : e[x]) {
            if (d[i][0][0] == -1) {
                d[i][0] = {d[x][y][0] + 1, d[x][y][1]};
                q.push({i, 0});
            }
            else if (d[i][1][0] == -1 && d[i][0][1] != d[x][y][1]) {
                d[i][1] = {d[x][y][0] + 1, d[x][y][1]};
                q.push({i, 1});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (d[i][0][0] == 0) {
            cout << d[i][1][0] << " ";
        }
        else {
            cout << d[i][0][0] << " ";
        }
    }
    return 0;
}