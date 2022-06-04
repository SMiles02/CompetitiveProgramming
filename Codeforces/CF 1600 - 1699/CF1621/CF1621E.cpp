#include <bits/stdc++.h>
#define ll long long
using namespace std;

template<class T, class U> struct lazy_segtree {
    // range [0,n]

    // merge(ID,x) = x
    const T ID = 1e9;
    int n;
    vector<T> data;
    vector<U> lazy;
    lazy_segtree(int n) : n(n), data(n * 4 + 4, 0), lazy(n * 4 + 4) {}
    
    T merge(T a, T b) {
        // The main operation
        return min(a, b);
    }

    void passDown(int i) {
        // Pushing the lazy values down
        lazy[i * 2 + 1] += lazy[i];
        lazy[i * 2 + 2] += lazy[i];
        lazy[i] = 0;
    }

    T calc(int i) {
        // Value at this node
        return data[i] + lazy[i];
    }

    void recalc(int i) {
        data[i] = merge(calc(i * 2 + 1), calc(i * 2 + 2));
    }   

    void update(int i, int l, int r, int qL, int qR, T x) {
        if (r < qL || qR < l)
            return;
        if (qL <= l && r <= qR) {
            // Update goes in here
            lazy[i] += x; 
            return;
        }
        passDown(i);
        update(i * 2 + 1, l, l + (r - l) / 2, qL, qR, x);
        update(i * 2 + 2, l + (r - l) / 2 + 1, r, qL, qR, x);
        recalc(i);
    }
    void update(int qL, int qR, T x) { update(0, 0, n, qL, qR, x); }
    
    T query(int i, int l, int r, int qL, int qR) {
        if (r < qL || qR < l)
            return ID;
        if (qL <= l && r <= qR)
            return calc(i);
        passDown(i);
        T x = merge(query(i * 2 + 1, l, l + (r - l) / 2, qL, qR), query(i * 2 + 2, l + (r - l) / 2 + 1, r, qL, qR));
        recalc(i);
        return x;
    }
    T query(int l, int r) { return query(0, 0, n, l, r); }
    T query_all() { return calc(0); }
};

const int N = 2e5;
lazy_segtree<int, int> seg(N);

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), k(m);
    vector<ll> s(m);
    vector<vector<int>> b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < m; ++i)
        seg.update(1, a[i], 1);
    for (int i = 0; i < m; ++i) {
        cin >> k[i];
        b[i].resize(k[i]);
        for (int j = 0; j < k[i]; ++j) {
            cin >> b[i][j];
            s[i] += b[i][j];
        }
        seg.update(1, (s[i] + k[i] - 1) / k[i], -1);
    }
    for (int i = 0; i < m; ++i) {
        seg.update(1, (s[i] + k[i] - 1) / k[i], 1);
        for (int j = 0; j < k[i]; ++j) {
            seg.update(1, (s[i] - b[i][j] + k[i] - 2) / (k[i] - 1), -1);
            cout << (seg.query_all() >= 0);
            seg.update(1, (s[i] - b[i][j] + k[i] - 2) / (k[i] - 1), 1);
        }
        seg.update(1, (s[i] + k[i] - 1) / k[i], -1);
    }
    cout << "\n";
    for (int i = 0; i < m; ++i)
        seg.update(1, a[i], -1);
    for (int i = 0; i < m; ++i)
        seg.update(1, (s[i] + k[i] - 1) / k[i], 1);
}
  
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}