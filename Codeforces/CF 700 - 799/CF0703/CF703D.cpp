#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int n) : n(n), bit(n + 1) {}
    void update(int x, int d) { for (int i = x; i <= n; i += i & -i) bit[i] ^= d; }
    int query(int x) {
        int rtn = 0;
        for (int i = x; i; i -= i & -i) rtn ^= bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) ^ query(x - 1); }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, l, r, id;
    cin >> n;
    int a[n + 1];
    map<int, int> last;
    BIT bit(n);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> q;
    int ans[q], dn = 0;
    array<int, 3> queries[q];
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        queries[i] = {r, l, i};
    }
    sort(queries, queries + q);
    for (int i = 0; i < q; ++i) {
        l = queries[i][1];
        r = queries[i][0];
        id = queries[i][2];
        while (dn < r) {
            ++dn;
            if (last[a[dn]])
                bit.update(last[a[dn]], a[dn]);
            last[a[dn]] = dn;
        }
        ans[id] = bit.query(l, r);
    }
    for (int i = 0; i < q; ++i)
        cout << ans[i] << "\n";
    return 0;
}