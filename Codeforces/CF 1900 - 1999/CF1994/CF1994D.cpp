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

const int N = 2005;
vector<int> mod[N][N];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            mod[i][j].clear();
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; j < n; ++j) {
            mod[j][a[i] % j].push_back(i);
        }
    }
    disjoint_set_union dsu(n);
    vector<array<int, 2>> ans;
    for (int i = n - 1; i > 0; --i) {
        bool done = false;
        for (int j = 0; j < i; ++j) {
            while (mod[i][j].size() > 1 && !done) {
                int x = mod[i][j].back(), y;
                mod[i][j].pop_back();
                y = mod[i][j].back();
                if (!dsu.connected(x, y)) {
                    dsu.unite(x, y);
                    ans.push_back({x, y});
                    done = true;
                }
            }
        }
    }
    cout << "YES\n";
    reverse(ans.begin(), ans.end());
    for (auto [x, y] : ans) {
        cout << x << " " << y << "\n";
    }
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