#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
int n;
bitset<N> e[N];

vector<int> bfs(int s) {
    vector<int> d(n + 1, N);
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i)
            if (e[x][i] && d[i] == N) {
                q.push(i);
                d[i] = d[x] + 1;
            }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, s, t, ans = 0;
    cin >> n >> m >> s >> t;
    while (m--) {
        int x, y;
        cin >> x >> y;
        e[x][y] = e[y][x] = 1;
    }
    vector<int> p = bfs(s), q = bfs(t);
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            ans += (!e[i][j] && p[t] <= min(p[i] + q[j], p[j] + q[i]) + 1);
    cout << ans;
    return 0;
}