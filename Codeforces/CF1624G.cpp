#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> pt, rk;
    DSU(int n) : pt(n + 1), rk(n + 1, 1) {
        for (int i = 1; i <= n; ++i)
            pt[i] = i;
    }
    int find(int i) {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
        }
    }
};

void solve() {
    int n, m, x, y, z, ans = 0, cur;
    cin >> n >> m;
    vector<array<int, 3>> e(m);
    for (int i = 0; i < m; ++i)
        cin >> e[i][0] >> e[i][1] >> e[i][2];
    for (int i = 29; i >= 0; --i) {
        cur = ans;
        for (int j = i - 1; j >= 0; --j)
            cur |= (1 << j);
        DSU dsu(n);
        for (auto i : e)
            if ((i[2] & cur) == i[2])
                dsu.unite(i[0], i[1]);
        if (dsu.rk[dsu.find(1)] < n)
            ans |= (1 << i);
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