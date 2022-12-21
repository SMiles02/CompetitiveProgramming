#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct DSU {
    vector<int> pt, rk;
    DSU(int n) : pt(n + 1), rk(n + 1, 1) {
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

void solve() {
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    array<int, 2> a[n];
    DSU dsu(n);
    map<int, int> m;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0];
        a[i][1] = i + 1;
        if (m[a[i][0]] == 0)
            m[a[i][0]] = i + 1;
        else
            m[a[i][0]] = min(m[a[i][0]], i + 1);
    }
    sort(a, a + n);
    for (int i = 1; i < n; ++i)
        if (a[i][0] - a[i - 1][0] <= k) {
            v[max(a[i][1], a[i - 1][1])].push_back(min(a[i][1], a[i - 1][1]));
            v[max(m[a[i][0]], m[a[i - 1][0]])].push_back(min(m[a[i][0]], m[a[i - 1][0]]));
        }
    for (int i = 1; i <= n; ++i) {
        for (int j : v[i])
            dsu.unite(i, j);
        ans += dsu.rk[dsu.find_set(i)];
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}