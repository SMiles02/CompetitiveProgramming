#include <bits/stdc++.h>
using namespace std;

struct disjoint_set_union {
    vector<int> p, sz;
    disjoint_set_union(int n) : p(n + 1), sz(n + 1, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find_set(int i) {
        return i == p[i] ? i : p[i] = find_set(p[i]);
    }
    void unite(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (sz[i] < sz[j])
                swap(i, j);
            p[j] = i;
            sz[i] += sz[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    disjoint_set_union dsu(n);
    vector<array<int, 3>> e(m);
    for (auto& [w, u, v] : e) {
        cin >> u >> v >> w;
    }
    sort(e.rbegin(), e.rend());
    while (!e.empty()) {
        vector<array<int, 3>> cur;
        cur.push_back(e.back());
        e.pop_back();
        while (!e.empty() && e.back()[0] == cur[0][0]) {
            cur.push_back(e.back());
            e.pop_back();
        }
        int t = cur.size();
        vector<bool> good(t);
        for (int i = 0; i < t; ++i) {
            good[i] = !dsu.connected(cur[i][1], cur[i][2]);
        }
        for (int i = 0; i < t; ++i) {
            ans += (good[i] && dsu.connected(cur[i][1], cur[i][2]));
            dsu.unite(cur[i][1], cur[i][2]);
        }
    }
    cout << ans << "\n";
    return 0;
}