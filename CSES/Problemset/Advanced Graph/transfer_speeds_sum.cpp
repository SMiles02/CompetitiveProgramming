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
            if (sz[i] < sz[j]) {
                swap(i, j);
            }
            p[j] = i;
            sz[i] += sz[j];
        }
    }
    int set_size(int x) {
        return sz[find_set(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    long long ans = 0;
    cin >> n;
    vector<array<int, 3>> e(n - 1);
    disjoint_set_union dsu(n);
    for (auto &[w, x, y] : e) {
        cin >> x >> y >> w;
    }
    sort(e.rbegin(), e.rend());
    for (auto &[w, x, y] : e) {
        ans += 1LL * dsu.set_size(x) * dsu.set_size(y) * w;
        dsu.unite(x, y);
    }
    cout << ans;
    return 0;
}