#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> e[N];
int n, d[2][N];

void dfs(int c, int p, int dt, int x) {
    d[x][c] = dt;
    for (int i : e[c])
        if (i != p)
            dfs(i, c, dt + 1, x);
}

int find_max(int i) {
    int ans = 0;
    for (int j = 1; j <= n; ++j)
        if (d[i][j] > d[i][ans])
            ans = j;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x, y;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0, 0, 0);
    dfs(x = find_max(0), 0, 0, 0);
    dfs(y = find_max(0), 0, 0, 1);
    vector<int> v(n + 2);
    for (int i = 1; i <= n; ++i)
        if (i != x && i != y)
            ++v[max(d[0][i], d[1][i])];
    for (int i = n; i > 0; --i)
        v[i] += v[i + 1];
    for (int i = 1; i <= n; ++i) {
        if (d[0][y] < i)
            cout << n << " ";
        else
            cout << n - v[i] - 1 << " ";
    }
    return 0;
}