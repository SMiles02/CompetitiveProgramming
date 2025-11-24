#include <bits/stdc++.h>
using namespace std;

struct fenwick {
    int n;
    vector<int> bit;
    fenwick(int n) : n(n), bit(n + 1) {}
    void update(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), ans(q), v;
    vector<vector<array<int, 2>>> queries(n + 1);
    fenwick bit(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries[r].push_back({l, i});
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        while (!v.empty() && a[v.back()] < a[i]) {
            v.pop_back();
        }
        bit.update(i, 1);
        if (!v.empty()) {
            bit.update(v.back(), -1);
        }
        v.push_back(i);
        for (auto [l, id] : queries[i]) {
            ans[id] = bit.query(l, i);
        }
    }
    for (int i : ans) {
        cout << i << "\n";
    }
    return 0;
}