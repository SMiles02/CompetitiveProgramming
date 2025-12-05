#include <bits/stdc++.h>
using namespace std;

struct fenwick_tree {
    int n;
    vector<int> bit;
    fenwick_tree(int n) : n(n), bit(n + 1) {}
    void update(int x, int d) {
        for (int i = x; i <= n; i += i & -i) {
            bit[i] += d;
        }
    }
    int query(int x) {
        int sum = 0;
        for (int i = x; i; i -= i & -i) {
            sum += bit[i];
        }
        return sum;
    }
    int query(int x, int y) {
        return query(y) - query(x - 1);
    }
};

int find_index(vector<int>& v, int x) {
    int l = 0, r = v.size() - 1, m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (v[m] < x) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> x(n), y(n + 2), ans(q);
    vector<array<int, 4>> queries(q);
    vector<vector<array<int, 4>>> process(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        y[i] = x[i];
    }
    y[n] = 1e9 + 1;
    y[n + 1] = 0;
    sort(y.begin(), y.end());
    fenwick_tree bit(n + 1);
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> queries[i][j];
        }
        int ql = find_index(y, queries[i][2]), qr = find_index(y, queries[i][3]);
        if (y[qr] != queries[i][3]) {
            if (ql == qr) {
                continue;
            }
            --qr;
        }
        process[queries[i][1]].push_back({i, ql, qr, 1});
        process[queries[i][0] - 1].push_back({i, ql, qr, -1});
    }
    for (int i = 0; i < n; ++i) {
        bit.update(find_index(y, x[i]), 1);
        for (auto [qi, ql, qr, qs] : process[i + 1]) {
            ans[qi] += bit.query(ql, qr) * qs;
        }
    }
    for (int i : ans) {
        cout << i << "\n";
    }
    return 0;
}