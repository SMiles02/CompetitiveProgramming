#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

struct DSU {
    vector<int> pt, rk;
    DSU(int n) : pt(n + 1), rk(n + 1, 1) {
        for (int i = 0; i <= n; ++i)
            pt[i] = i;
    }
    int find_set(int i) {
        return i == pt[i] ? i : pt[i] = find_set(pt[i]);
    }
    void unite(int i, int j) {
        // cout << i << " " << j << "\n";
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

ll sq(ll x) {
    return x * x;
}

ll dt(ll a, ll b, ll c, ll d) {
    return sq(a - c) + sq(b - d);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, a, b, c, d;
    cin >> n;
    cin >> a >> b >> c >> d;
    int x[n][3];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> x[i][j];
    DSU dsu(n + 3);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (sq(x[i][2] + x[j][2]) >= dt(x[i][0], x[i][1], x[j][0], x[j][1]) && dt(x[i][0], x[i][1], x[j][0], x[j][1]) >= sq(x[i][2] - x[j][2]))
                dsu.unite(i, j);
    for (int i = 0; i < n; ++i)
        if (sq(x[i][2]) == dt(a, b, x[i][0], x[i][1]))
            dsu.unite(n, i);
    for (int i = 0; i < n; ++i)
        if (sq(x[i][2]) == dt(c, d, x[i][0], x[i][1]))
            dsu.unite(n + 1, i);
    if (dsu.connected(n, n + 1))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}