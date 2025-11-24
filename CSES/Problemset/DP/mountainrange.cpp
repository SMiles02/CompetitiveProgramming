#include <bits/stdc++.h>
using namespace std;

vector<int> find_range(int n, vector<int>& h) {
    vector<int> v = {0}, last(n + 2);
    for (int i = 1; i <= n; ++i) {
        while (h[i] > h[v.back()]) {
            v.pop_back();
        }
        last[i] = v.back();
        v.push_back(i);
    }
    return last;
}

struct segment_tree {
    int n;
    vector<int> s;
    int merge(int a, int b) {
        return max(a, b);
    }
    segment_tree(int n) : n(n), s(n * 4) {}
    void update(int i, int l, int r, int x, int y) {
        if (l == r) {
            s[i] = y;
            return;
        }
        if (x <= l + (r - l) / 2) {
            update(i * 2 + 1, l, l + (r - l) / 2, x, y);
        }
        else {
            update(i * 2 + 2, l + (r - l) / 2 + 1, r, x, y);
        }
        s[i] = merge(s[i * 2 + 1], s[i * 2 + 2]);
    }
    void update(int x, int y) {
        update(0, 1, n, x, y);
    }
    int query(int i, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return s[i];
        }
        if (qr < l || r < ql) {
            return 0;
        }
        return merge(query(i * 2 + 1, l, l + (r - l) / 2, ql, qr), query(i * 2 + 2, l + (r - l) / 2 + 1, r, ql, qr));
    }
    int query(int l, int r) {
        return query(0, 1, n, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 2);
    a[0] = a[n + 1] = 1e9 + 7;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> b = a, l, r;
    reverse(b.begin(), b.end());
    l = find_range(n, a);
    r = find_range(n, b);
    for (int i = 0; i <= n + 1; ++i) {
        r[i] = n + 1 - r[i];
    }
    reverse(r.begin(), r.end());
    segment_tree dp(n);
    vector<array<int, 2>> v(n);
    for (int i = 1; i <= n; ++i) {
        v[i - 1] = {a[i], i};
    }
    sort(v.begin(), v.end());
    for (auto &[ai, i] : v) {
        dp.update(i, dp.query(l[i] + 1, r[i] - 1) + 1);
    }
    cout << dp.query(1, n);
    return 0;
}