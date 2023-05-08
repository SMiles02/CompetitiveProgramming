#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

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

const int N = 2e5 + 1;
int vis;
vector<int> e[N];
bitset<N> dn, is_root;

void dfs(int c, bool is_four) {
    dn[c] = 1;
    ++vis;
    for (auto i : e[c])
        if (!dn[i] && (e[i].size() == 2) ^ (is_four))
            dfs(i, is_four);
}

void solve() {
    int n, m, k, x, y, roots = 0, sides = 0;
    bool ok = true;
    cin >> n >> m;
    k = sqrt(n);
    DSU dsu(n), test_dsu(n);
    for (int i = 1; i <= n; ++i) {
        e[i].clear();
        dn[i] = 0;
        is_root[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        dsu.unite(x, y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() == 2)
            ++sides;
        else if (e[i].size() == 4) {
            ++roots;
            is_root[i] = 1;
        }
        else
            ok = false;
    }
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() == 2 && !dn[i]) {
            vis = 0;
            dfs(i, false);
            if (vis != k - 1)
                ok = false;
        }
        if (e[i].size() == 4 && !dn[i]) {
            vis = 0;
            dfs(i, true);
            if (vis != k)
                ok = false;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() == 2) {
            for (int j : e[i])
                if (e[j].size() == 2)
                    test_dsu.unite(i, j);
        }
        else if (e[i].size() == 4)
            for (int x : e[i])
                for (int y : e[i])
                    if (e[x].size() == 2 && e[y].size() == 2)
                        test_dsu.unite(x, y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (e[i].size() == 2 && test_dsu.pt[test_dsu.find_set(i)] == i) {
            ++cnt;
            if (test_dsu.rk[i] != k - 1)
                ok = false;
        }
    if (k * k != n || k * (k + 1) != m || dsu.rk[dsu.find_set(1)] != n || cnt != k || !ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}