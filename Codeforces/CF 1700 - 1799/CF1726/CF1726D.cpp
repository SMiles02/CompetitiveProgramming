#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
    vector<array<int, 3>> e(m);
    string s(m, '0');
    for (int i = 0; i < m; ++i) {
        cin >> e[i][0] >> e[i][1];
        e[i][2] = i;
    }
    if (m < n + 2) {
        disjoint_set_union p(n);
        for (int i = 0; i < m; ++i) {
            if (p.connected(e[i][0], e[i][1])) {
                s[i] = '1';
            }
            p.unite(e[i][0], e[i][1]);
        }
    }
    else {
        for (int _ = 0; _ < 50; ++_) {
            disjoint_set_union p(n), q(n);
            shuffle(e.begin(), e.end(), rng);
            bool ok = true;
            s = string(m, '0');
            for (int i = 0; i < m; ++i) {
                if (p.connected(e[i][0], e[i][1])) {
                    if (q.connected(e[i][0], e[i][1])) {
                        ok = false;
                    }
                    s[e[i][2]] = '1';
                    q.unite(e[i][0], e[i][1]);
                }
                else {
                    p.unite(e[i][0], e[i][1]);
                }
            }
            if (ok) {
                break;
            }
        }
    }
    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}