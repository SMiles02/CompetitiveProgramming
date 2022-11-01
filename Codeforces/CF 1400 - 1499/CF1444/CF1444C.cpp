#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> pt, sz;
    vector<array<int, 2>> changes;
    DSU(int n) : pt(n + 1), sz(n + 1, 1) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }
    int find_set(int i) {
        return i == pt[i] ? i : find_set(pt[i]);
    }
    bool unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            pt[j] = i;
            sz[i] += sz[j];
            changes.push_back({i, j});
            return true;
        }
        return false;
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
    void roll_back() {
        array<int, 2> a = changes.back();
        changes.pop_back();
        pt[a[1]] = a[1];
        sz[a[0]] -= sz[a[1]];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k, x, y, change_cnt;
    cin >> n >> m >> k;
    vector<int> c(n + 1);
    vector<bool> ok(k + 1, true);
    vector<vector<array<int, 2>>> same_group(k + 1);
    map<array<int, 2>, vector<array<int, 2>>> diff_group;
    DSU dsu(n * 2 + 1);
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    while (m--) {
        cin >> x >> y;
        if (c[x] == c[y]) {
            dsu.unite(x, y + n);
            dsu.unite(x + n, y);
        }
        else
            diff_group[{min(c[x], c[y]), max(c[x], c[y])}].push_back({x, y});
    }
    for (int i = 1; i <= n; ++i)
        if (dsu.connected(i, i + n) && ok[c[i]]) {
            ok[c[i]] = false;
            --k;
        }
    long long ans = (1LL * k * (k - 1)) / 2;
    for (auto pairings : diff_group)
        if (ok[pairings.first[0]] && ok[pairings.first[1]]) {
            change_cnt = 0;
            for (auto i : pairings.second) {
                change_cnt += dsu.unite(i[0], i[1] + n) + dsu.unite(i[0] + n, i[1]);
                if (dsu.connected(i[0], i[0] + n)) {
                    --ans;
                    break;
                }
            }
            while (change_cnt--)
                dsu.roll_back();
        }
    cout << ans;
    return 0;
}