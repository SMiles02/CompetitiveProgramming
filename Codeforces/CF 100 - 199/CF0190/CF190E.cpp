#include <bits/stdc++.h>
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, x, y, cnt = 0;
    cin >> n >> m;
    vector<vector<int>> v(n + 1), ans(n + 1);
    vector<int> p(n + 2);
    DSU dsu(n);
    while (m--) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        v[i].push_back(0);
        v[i].push_back(n + 1);
        v[i].push_back(i);
        sort(v[i].begin(), v[i].end());
        for (int j = 1; j < v[i].size(); ++j)
            if (v[i][j - 1] + 1 != v[i][j]) {
                dsu.unite(v[i][j - 1] + 1, i);
                ++p[v[i][j - 1] + 1];
                --p[v[i][j] - 1];
            }
    }
    for (int i = 1; i <= n; ++i) {
        p[i] += p[i - 1];
        if (p[i])
            dsu.unite(i, i + 1);
    }
    for (int i = 1; i <= n; ++i) {
        ans[dsu.find_set(i)].push_back(i);
        if (dsu.find_set(i) == i)
            ++cnt;
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; ++i)
        if (!ans[i].empty()) {
            cout << ans[i].size() << " ";
            for (int j : ans[i])
                cout << j << " ";
            cout << "\n";
        }
    return 0;
}