template<class T> struct implicit_segtree {
    // merge(ID, x) = x
    // range [0, n]
    const T ID = 0;
    T merge(T a, T b) { return max(a, b); }
    struct node {
        T val = 0;
        node *l, *r;
    };
    deque<node> buffer;
    node *newnode() {
        buffer.emplace_back();
        return &buffer.back();
    }
    int n;
    node *root;
    implicit_segtree(int n) : n(n) {root = newnode();}
    void update(node *&v, int l, int r, int i, T x) {
        if (i < l || r < i)
            return;
        if (!v) 
            v = newnode();
        v->val = merge(v->val, x);
        if (l==r)
            return;
        update(v->l, l, (l+r)>>1, i, x);
        update(v->r, (l+r+2)>>1, r, i, x);
    }
    void update(int i, T x) {
        update(root, 0, n, i, x);
    }
    T query(node* v, int cL, int cR, int l, int r) {
        if (r < cL || cR < l || !v)
            return ID;
        if (l <= cL && cR <= r)
            return v->val;
        return merge(query(v->l, cL, (cL+cR)>>1, l, r), query(v->r, (cL+cR+2)>>1, cR, l, r));
    }
    T query(int l, int r) {
        return query(root, 0, n, l, r);
    }
};