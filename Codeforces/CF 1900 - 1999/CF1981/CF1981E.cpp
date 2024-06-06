#include <bits/stdc++.h>
using namespace std;

struct disjoint_set_union {
    vector<int> p, sz;
    disjoint_set_union(int n) : p(n), sz(n, 1) {
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

map<int, int> compress(vector<int> v) {
    sort(v.begin(), v.end());
    int id = 0;
    map<int, int> m;
    for (int i = 0; i < v.size(); ++i) {
        if (i == 0 || v[i] != v[i - 1]) {
            m[v[i]] = id++;
        }
    }
    return m;
}

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    set<array<int, 2>> s;
    vector<array<int, 3>> a(n), edges;
    vector<int> all_times;
    vector<vector<int>> entry(n * 2), exit(n * 2);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        all_times.push_back(a[i][0]);
        all_times.push_back(a[i][1]);
    }
    map<int, int> compress_map = compress(all_times);
    for (int i = 0; i < n; ++i) {
        entry[compress_map[a[i][0]]].push_back(i);
        exit[compress_map[a[i][1]]].push_back(i);
    }
    for (int i = 0; i < n * 2; ++i) {
        for (int j : entry[i]) {
            s.insert({a[j][2], j});
        }
        for (int j : exit[i]) {
            if (s.upper_bound({a[j][2], j}) != s.end()) {
                auto [x, k] = *s.upper_bound({a[j][2], j});
                edges.push_back({x - a[j][2], j, k});
            }
            if (s.find({a[j][2], j}) != s.begin()) {
                auto [x, k] = *(--s.find({a[j][2], j}));
                edges.push_back({a[j][2] - x, j, k});
            }
        }
        for (int j : exit[i]) {
            s.erase({a[j][2], j});
        }
    }
    disjoint_set_union dsu(n);
    sort(edges.begin(), edges.end());
    for (auto& [z, x, y] : edges) {
        if (!dsu.connected(x, y)) {
            dsu.unite(x, y);
            ans += z;
        }
    }
    if (dsu.sz[dsu.find_set(0)] < n) {
        ans = -1;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}