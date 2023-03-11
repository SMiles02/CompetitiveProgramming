#include <bits/stdc++.h>
using namespace std;

// Arithmetic Progression Segtree

template<class T> struct progression_segtree {
    // merge(ID, x) = x
    // range [0, n]
    const T ID = 0;
    int n;
    vector<T> seg;
    vector<array<T, 2>> lazy;
    vector<int> range_length;
    T cur_query_ans;
    T merge(T a, T b) {
        return a + b;
    }
    void get_range_sizes(int i, int l, int r) {
        range_length[i] = r - l + 1;
        if (l == r)
            return;
        get_range_sizes(i * 2 + 1, l, l + (r - l) / 2);
        get_range_sizes(i * 2 + 2, l + (r - l) / 2 + 1, r);
    }
    progression_segtree(int n) : n(n), seg((n + 1) * 4), lazy((n + 1) * 4), range_length((n + 1) * 4) {
        get_range_sizes(0, 0, n);
    }
    T calc_progression(T start_val, T common_diff, int n) {
        return start_val * n + ((1LL * n * (n - 1)) / 2) * common_diff;
    }
    T get_val(int i) {
        return seg[i] + calc_progression(lazy[i][0], lazy[i][1], range_length[i]);
    }
    void pass_down(int i) {
        lazy[i * 2 + 1][0] += lazy[i][0];
        lazy[i * 2 + 1][1] += lazy[i][1];
        lazy[i * 2 + 2][0] += lazy[i][0] + lazy[i][1] * range_length[i * 2 + 1];
        lazy[i * 2 + 2][1] += lazy[i][1];
        lazy[i][0] = 0;
        lazy[i][1] = 0;
    }
    void recalculate(int i) {
        seg[i] = merge(get_val(i * 2 + 1), get_val(i * 2 + 2));
    }
    void set(int i, int cl, int cr, int p, T x) {
        if (cl == cr) {
            seg[i] = x;
            lazy[i][0] = lazy[i][1] = 0;
            return;
        }
        pass_down(i);
        if (p <= cl + (cr - cl) / 2)
            set(i * 2 + 1, cl, cl + (cr - cl) / 2, p, x);
        else
            set(i * 2 + 2, cl + (cr - cl) / 2 + 1, cr, p, x);
        recalculate(i);
    }
    void set(int p, T x) {
        set(0, 0, n, p, x);
    }
    void update(int i, int cl, int cr, int ql, int qr, T start_val, T common_diff) {
        if (cr < ql || qr < cl)
            return;
        if (ql <= cl && cr <= qr) {
            lazy[i][0] += start_val + common_diff * (cl - ql);
            lazy[i][1] += common_diff;
            return;
        }
        pass_down(i);
        update(i * 2 + 1, cl, cl + (cr - cl) / 2, ql, qr, start_val, common_diff);
        update(i * 2 + 2, cl + (cr - cl) / 2 + 1, cr, ql, qr, start_val, common_diff);
        recalculate(i);
    }
    void update(int ql, int qr, T start_val, T common_diff) {
        update(0, 0, n, ql, qr, start_val, common_diff);
    }
    void query(int i, int cl, int cr, int ql, int qr) {
        if (cr < ql || qr < cl)
            return;
        if (ql <= cl && cr <= qr) {
            cur_query_ans = merge(cur_query_ans, get_val(i));
            return;
        }
        pass_down(i);
        query(i * 2 + 1, cl, cl + (cr - cl) / 2, ql, qr);
        query(i * 2 + 2, cl + (cr - cl) / 2 + 1, cr, ql, qr);
        recalculate(i);
    }
    T query(int ql, int qr) {
        cur_query_ans = ID;
        query(0, 0, n, ql, qr);
        return cur_query_ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, t, x, y;
    cin >> n >> q;
    progression_segtree<long long> seg(n);
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        seg.set(i, x);
    }
    while (q--) {
        cin >> t >> x >> y;
        if (t == 1)
            seg.update(x, y, 1, 1);
        else
            cout << seg.query(x, y) << "\n";
    }
    return 0;
}