#include <bits/stdc++.h>
using namespace std;

struct disjoint_set_union {
    vector<int> p, sz, black;
    disjoint_set_union(int n) : p(n + 1), sz(n + 1, 1), black(n + 1) {
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
            black[i] += black[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    disjoint_set_union dsu(n);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        dsu.unite(i, p[i]);
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ++dsu.black[dsu.find_set(i + 1)];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << dsu.black[dsu.find_set(i)] << " ";
    }
    cout << "\n";
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