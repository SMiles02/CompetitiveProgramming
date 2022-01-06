// Verification: https://codeforces.com/contest/1621/submission/141776357

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
        cout << "merge(a, b) not added.\n";
        return min(a, b);
    }

    void passDown(int i) {
        // Pushing the lazy values down
        cout << "passDown(i) not added.\n";
        lazy[i * 2 + 1] += lazy[i];
        lazy[i * 2 + 2] += lazy[i];
        lazy[i] = 0;
    }

    T calc(int i) {
        // Value at this node
        cout << "calc(i) not added.\n";
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
            cout << "Update not added.\n";
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