#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1, INF = 1e9;
vector<int> e[N];
bitset<N> is_bonus;

struct DSU {
    vector<int> pt, rk;
    DSU(int n) : pt(n + 1), rk(n + 1, 1) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
         }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

void solve() {
    int n, m, p, b, x, y, cnt = 0, moves = 0;
    cin >> n >> m;
    cin >> p >> b;
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        is_bonus[i] = 0;
    }
    vector<int> v(p), w(b);
    for (auto &i : v)
        cin >> i;
    for (auto &i : w) {
        cin >> i;
        is_bonus[i] = 1;
    }
    is_bonus[1] = 1;
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
        if (is_bonus[x] && is_bonus[y])
            dsu.unite(x, y);
    }
    for (auto i : v) {
        if (i == 1) {
            cout << "YES\n";
            return;
        }
        for (auto j : e[i]) {
            if (j == 1) {
                cout << "YES\n";
                return;
            }
            if (dsu.connected(j, 1)) {
                ++cnt;
                x = i;
                break;
            }
        }
    }
    if (cnt == 0) {
        cout << "NO\n";
        return;
    }
    if (cnt > 1) {
        cout << "YES\n";
        return;
    }
    for (auto i : v)
        if (i != x)
            for (auto j : e[i])
                if (is_bonus[j]) {
                    if (dsu.rk[dsu.find_set(j)] > 1) {
                        cout << "YES\n";
                        return;
                    }
                    ++moves;
                }
    vector<int> d(n + 1, INF);
    d[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        x = q.front();
        q.pop();
        for (int i : e[x])
            if (is_bonus[i] && d[i] == INF) {
                d[i] = d[x] + 1;
                q.push(i);
            }
    }
    if (d[1] <= moves + 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}