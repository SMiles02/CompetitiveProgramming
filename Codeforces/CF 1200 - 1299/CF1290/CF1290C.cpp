#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> pt, sz, wt;
    DSU(int n) : pt(n * 2 + 2), sz(n * 2 + 2, 1), wt(n * 2 + 2) {
        for (int i = 0; i < n * 2 + 2; ++i)
            pt[i] = i;
        for (int i = 1; i <= n; ++i)
            wt[i] = 1;
        wt[0] = 1e9;
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            pt[j] = i;
            sz[i] += sz[j];
            wt[i] += wt[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
    int cost(int x) {
        return wt[find_set(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, x, y, ans = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "!" + s;
    vector<vector<int>> v(n + 1);
    DSU dsu(k);
    for (int i = 1; i <= k; ++i) {
        cin >> x;
        while (x--) {
            cin >> y;
            v[y].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!v[i].empty()) {
            if (v[i].size() == 1)
                v[i].push_back(0);
            if (s[i] == '0') {
                if (!dsu.connected(v[i][0], v[i][1] + k + 1)) {
                    ans -= min(dsu.cost(v[i][0]), dsu.cost(v[i][0] + k + 1));
                    ans -= min(dsu.cost(v[i][1]), dsu.cost(v[i][1] + k + 1));
                    dsu.unite(v[i][0], v[i][1] + k + 1);
                    dsu.unite(v[i][0] + k + 1, v[i][1]);
                    ans += min(dsu.cost(v[i][0]), dsu.cost(v[i][0] + k + 1));
                }
            }
            else {
                if (!dsu.connected(v[i][0], v[i][1])) {
                    ans -= min(dsu.cost(v[i][0]), dsu.cost(v[i][0] + k + 1));
                    ans -= min(dsu.cost(v[i][1]), dsu.cost(v[i][1] + k + 1));
                    dsu.unite(v[i][0], v[i][1]);
                    dsu.unite(v[i][0] + k + 1, v[i][1] + k + 1);
                    ans += min(dsu.cost(v[i][0]), dsu.cost(v[i][0] + k + 1));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}