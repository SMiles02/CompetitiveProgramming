#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 3e5 + 3, INF = 1e9;
int d[2][N];
vector<int> e[N];
bitset<N> special, dn;

void bfs(int x, int src) {
    queue<array<int, 2>> q;
    q.push({src, 0});
    dn[src] = 0;
    for (int i = 0; i < N; ++i)
        d[x][i] = INF;
    array<int, 2> a;
    while (!q.empty()) {
        a = q.front();
        q.pop();
        d[x][a[0]] = a[1];
        if (special[a[0]])
            d[x][0] = min(d[x][0], a[1]);
        for (int i : e[a[0]])
            if (!dn[i]) {
                q.push({i, a[1] + 1});
                dn[i] = 1;
            }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y, ans;
    cin >> n >> m;
    while (m--) {
        cin >> x >> y;
        if (x == 0)
            special[y] = 1;
        else {
            e[x].push_back(y);
            e[y].push_back(x);
        }
    }
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < N; ++j)
            d[i][j] = INF;
    bfs(0, 1);
    dn.reset();
    bfs(1, n);
    // cout << d[0][0] << " " << "\n";
    for (int i = 1; i <= n; ++i) {
        ans = min({d[0][n], d[0][0] + d[1][i] + 1, d[0][i] + d[1][0] + 1, d[0][0] + d[1][0] + 2});
        if (i == 1)
            ans = min(ans, d[1][0] + 1);
        if (i == n)
            ans = min(ans, d[0][0] + 1);
        if (ans == INF)
            ans = -1;
        cout << ans << " ";
    }
    return 0;
}