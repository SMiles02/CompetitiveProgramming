// probably the worst problem I've bothered to solve this year :))))

#include <bits/stdc++.h>
using namespace std;

const int N = 401;
int n, m;
string s[N], ans;
bitset<N> done[N];

struct DSU
{
    const int rows = 401, cols = 401;
    vector<int> pt, rk;
    set<array<int, 4>> edges;
    int convert(int i, int j) {
        return i * cols + j;
    }
    int find(int i) {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }
    int find(int i, int j) {
        return find(convert(i, j));
    }
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
    array<int, 4> array_form(int a, int b, int c, int d) {
        if (a > c)
            swap(a, c);
        if (b > d)
            swap(b, d);
        return {a, b, c, d};
    }
    void unite(int a, int b, int c, int d) {
        unite(convert(a, b), convert(c, d));
        edges.insert(array_form(a, b, c, d));
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    bool connected(int a, int b, int c, int d) {
        return connected(convert(a, b), convert(c, d));
    }
    bool hasEdge(int a, int b, int c, int d) {
        return edges.find(array_form(a, b, c, d)) != edges.end();
    }
    void clean() {
        for (int i = 0; i <= rows * cols; ++i) {
            rk[i] = 1;
            pt[i] = i;
        }
        edges.clear();
    }
    DSU(int useless) : pt(rows * cols + 1), rk(rows * cols + 1) {
        clean();
    }
};

DSU dsu(69);

bool ok(int x, int y) {
    return (0 <= x && x < n * 2 && 0 <= y && y < m * 2 && s[x / 2][y / 2] == '*' && !done[x][y]);
}

bool same(int x, int y) {
    return (x / 2 == y / 2);
}

bool tryGo(int a, int b, int c, int d) {
    if (ok(c, d)) {
        if (same(a, c) && same(b, d))
            return true;
        if (dsu.hasEdge(a / 2, b / 2, c / 2, d / 2))
            return true;
        if (!dsu.connected(a / 2, b / 2, c / 2, d / 2)) {
            dsu.unite(a / 2, b / 2, c / 2, d / 2);
            return true;
        }
    }
    return false;
}

void dfs(int x, int y) {
    done[x][y] = 1;
    if (x % 2 == 0 && y % 2 == 0) {
        if (!done[x + 1][y] && tryGo(x, y, x, y - 1)) {
            ans += "W";
            dfs(x, y - 1);
            return;
        }
        if (!done[x][y + 1] && tryGo(x, y, x - 1, y)) {
            ans += "N";
            dfs(x - 1, y);
            return;
        }
    }
    if (x % 2 == 0 && y % 2 == 1) {
        if (!done[x + 1][y] && tryGo(x, y, x, y + 1)) {
            ans += "E";
            dfs(x, y + 1);
            return;
        }
        if (!done[x][y - 1] && tryGo(x, y, x - 1, y)) {
            ans += "N";
            dfs(x - 1, y);
            return;
        }
    }
    if (x % 2 == 1 && y % 2 == 0) {
        if (!done[x - 1][y] && tryGo(x, y, x, y - 1)) {
            ans += "W";
            dfs(x, y - 1);
            return;
        }
        if (!done[x][y + 1] && tryGo(x, y, x + 1, y)) {
            ans += "S";
            dfs(x + 1, y);
            return;
        }
    }
    if (x % 2 == 1 && y % 2 == 1) {
        if (!done[x - 1][y] && tryGo(x, y, x, y + 1)) {
            ans += "E";
            dfs(x, y + 1);
            return;
        }
        if (!done[x][y - 1] && tryGo(x, y, x + 1, y)) {
            ans += "S";
            dfs(x + 1, y);
            return;
        }
    }
    if (x % 2 == 0 && y % 2 == 0) {
        if (tryGo(x, y, x, y + 1)) {
            ans += "E";
            dfs(x, y + 1);
        }
        else if (tryGo(x, y, x + 1, y)) {
            ans += "S";
            dfs(x + 1, y);
        }
        else if (tryGo(x, y, x, y - 1)) {
            ans += "W";
            dfs(x, y - 1);
        }
        else if (tryGo(x, y, x - 1, y)) {
            ans += "N";
            dfs(x - 1, y);
        }
        return;
    }
    if (x % 2 == 0 && y % 2 == 1) {
        if (tryGo(x, y, x + 1, y)) {
            ans += "S";
            dfs(x + 1, y);
        }
        else if (tryGo(x, y, x, y - 1)) {
            ans += "W";
            dfs(x, y - 1);
        }
        else if (tryGo(x, y, x - 1, y)) {
            ans += "N";
            dfs(x - 1, y);
        }
        else if (tryGo(x, y, x, y + 1)) {
            ans += "E";
            dfs(x, y + 1);
        }
        return;
    }
    if (x % 2 == 1 && y % 2 == 0) {
        if (tryGo(x, y, x - 1, y)) {
            ans += "N";
            dfs(x - 1, y);
        }
        else if (tryGo(x, y, x, y + 1)) {
            ans += "E";
            dfs(x, y + 1);
        }
        else if (tryGo(x, y, x + 1, y)) {
            ans += "S";
            dfs(x + 1, y);
        }
        else if (tryGo(x, y, x, y - 1)) {
            ans += "W";
            dfs(x, y - 1);
        }
        return;
    }
    if (x % 2 == 1 && y % 2 == 1) {
        if (tryGo(x, y, x, y - 1)) {
            ans += "W";
            dfs(x, y - 1);
        }
        else if (tryGo(x, y, x - 1, y)) {
            ans += "N";
            dfs(x - 1, y);
        }
        else if (tryGo(x, y, x, y + 1)) {
            ans += "E";
            dfs(x, y + 1);
        }
        else if (tryGo(x, y, x + 1, y)) {
            ans += "S";
            dfs(x + 1, y);
        }
        return;
    }
}

void solve() {
    cin >> n >> m;
    dsu.clean();
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n * 2; ++i)
        done[i].reset();
    ans = "";
    dfs(0, 0);
    ans += "N";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '*' && !done[i * 2][j * 2]) {
                // cout << i << " " << j << "\n";
                cout << "IMPOSSIBLE\n";
                return;
            }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}