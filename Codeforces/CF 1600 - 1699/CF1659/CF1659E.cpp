#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> pt, rk;
    vector<bool> even;
    DSU(int n) : pt(n + 1), rk(n + 1, 1), even(n + 1) {
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
            if (even[j])
                even[i] = true;
        }
    }
    bool connected(int x, int y) {
        return find_set(x) == find_set(y);
    }
    void set_even(int x) {
        even[find_set(x)] = true;
    }
    bool is_even(int x) {
        return even[find_set(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, q, x, y, z;
    cin >> n >> m;
    deque<DSU> dsu;
    DSU base(n);
    for (int i = 0; i < 30; ++i)
        dsu.emplace_back(base);
    while (m--) {
        cin >> x >> y >> z;
        for (int i = 0; i < 30; ++i) {
            if ((1 << i) & z)
                dsu[i].unite(x, y);
            if ((z & 1) == 0) {
                dsu[i].set_even(x);
                dsu[i].set_even(y);
            }
        }
    }
    cin >> q;
    while (q--) {
        cin >> x >> y;
        int ans = 2;
        for (int i = 1; i < 30; ++i)
            if (dsu[i].is_even(x))
                ans = 1;
        for (int i = 0; i < 30; ++i)
            if (dsu[i].connected(x, y))
                ans = 0;
        cout << ans << "\n";
    }
    return 0;
}