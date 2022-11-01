#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> pt, sz;
    DSU(int n) : pt(n + 1), sz(n + 1, 1) {
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
            if (sz[i] < sz[j])
                swap(i, j);
            pt[j] = i;
            sz[i] += sz[j];
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
};

const int N = 1001;
int a[N][N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    DSU dsu(n * 2);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (a[i][j] != a[j][i]) {
                if (a[i][j] < a[j][i] && !dsu.connected(i + n, j)) {
                    dsu.unite(i, j);
                    dsu.unite(i + n, j + n);
                }
                else if (a[i][j] > a[j][i] && !dsu.connected(i, j)) {
                    dsu.unite(i, j + n);
                    dsu.unite(i + n, j);
                }
            }
    set<int> s;
    for (int i = 1; i <= n; ++i)
        if (dsu.find_set(i) == i)
            s.insert(i);
    for (int i = 1; i <= n; ++i)
        if (s.count(dsu.find_set(i)))
            for (int j = 1; j <= n; ++j)
                swap(a[i][j], a[j][i]);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}