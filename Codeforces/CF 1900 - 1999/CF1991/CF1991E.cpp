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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> e(m);
    disjoint_set_union dsu(n * 2);
    for (auto &[x, y] : e) {
        cin >> x >> y;
    }
    for (auto [x, y] : e) {
        dsu.unite(x, y + n);
        dsu.unite(x + n, y);
    }
    if (dsu.connected(1, n + 1)) {
        cout << "Alice" << endl;
        for (int i = 0, x, y; i < n; ++i) {
            cout << "1 2" << endl;
            cin >> x >> y;
        }
    }
    else {
        cout << "Bob" << endl;
        vector<int> p, q;
        for (int i = 1; i <= n; ++i) {
            if (dsu.connected(1, i)) {
                p.push_back(i);
            }
            else {
                q.push_back(i);
            }
        }
        for (int i = 0, x, y; i < n; ++i) {
            cin >> x >> y;
            if ((x == 1 || y == 1) && !p.empty()) {
                cout << p.back() << " 1" << endl;
                p.pop_back();
            }
            else if ((x == 2 || y == 2) && !q.empty()) {
                cout << q.back() << " 2" << endl;
                q.pop_back();
            }
            else if ((x == 3 || y == 3) && !p.empty()) {
                cout << p.back() << " 3" << endl;
                p.pop_back();
            }
            else {
                cout << q.back() << " 3" << endl;
                q.pop_back();
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}