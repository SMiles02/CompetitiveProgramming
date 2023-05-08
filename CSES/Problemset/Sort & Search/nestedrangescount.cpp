#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n, rtn;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1) {}
    void update(int x, int d) { for (int i = x; i <= n; i += i & -i) bit[i] += d; }
    int query(int x) {
        rtn = 0;
        for (int i = x; i; i -= i & -i) rtn += bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) - query(x - 1); }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, cur = 0;
    cin >> n;
    BIT bit1(n * 2), bit2(n * 2);
    vector<int> inside(n), outside(n);
    vector<array<int, 2>> a(n);
    vector<vector<array<int, 2>>> e(n * 2 + 1);
    set<int> t;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i][0] >> a[i][1];
        t.insert(a[i][0]);
        t.insert(a[i][1]);
    }
    for (int i : t)
        m[i] = ++cur;
    for (int i = 0; i < n; ++i) {
        bit2.update(m[a[i][0]], 1);
        e[m[a[i][1]]].push_back({m[a[i][0]], i});
    }
    for (int i = 1; i <= n * 2; ++i) {
        sort(e[i].rbegin(), e[i].rend());
        for (auto j : e[i]) {
            inside[j[1]] = bit1.query(j[0], i);
            bit1.update(j[0], 1);
            bit2.update(j[0], -1);
            outside[j[1]] = bit2.query(j[0]);
        }
    }
    for (auto i : inside)
        cout << i << " ";
    cout << "\n";
    for (auto i : outside)
        cout << i << " ";
    return 0;
}