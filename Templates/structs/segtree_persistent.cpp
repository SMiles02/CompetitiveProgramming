template<class T> struct PST {
    // merge(ID,x) = x
    // range [0,n]
    const T ID = 0;
    T merge(T a, T b) { return a+b; }
    struct node {
        T val;
        node *l, *r;
        node(T x) : val(x) {}
    };
    deque<node> buffer;
    node *newnode(T x = ID) {
        buffer.emplace_back(x);
        return &buffer.back();
    }
    node *newnode(node *l, node *r) {
        auto x = newnode(merge(l->val,r->val));
        x->l = l, x->r = r;
        return x;
    }
    int n, a=1;
    node *roots[200005]; //change this to how many tree copies there can be
    PST(int n) : n(n) {roots[1] = build(0, n);}
    node *build(int l, int r) {
        if(l == r) 
            return newnode(ID);
        return newnode(build(l,(l+r)>>1),build((l+r+2)>>1, r));
    }
    node *update(node *v, int l, int r, int i, T x) {
        if(r < i || i < l)
            return v;
        if(l == r)
            return newnode(x);
        return newnode(update(v->l,l,(l+r)>>1,i,x), update(v->r,(l+r+2)>>1,r,i,x));
    }
    void update(int k, int i, T x) { roots[k] = update(roots[k], 0, n, i, x); }
    T query(node *v, int cL, int cR, int l, int r) {
        if (r<cL||cR<l)
            return ID;
        if (l<=cL&&cR<=r)
            return v->val;
        return merge(query(v->l,cL,(cL+cR)>>1,l,r), query(v->r,(cL+cR+2)>>1,cR,l,r));
    }
    T query(int k, int l, int r) { return query(roots[k],0,n,l,r); }
    void clone(int k) {
        roots[++a] = newnode(roots[k]->l, roots[k]->r);
        roots[a]->val = roots[k]->val;
    }
};

// seg.clone(k);
// Creates a copy of k at
// the newest position.

// seg.update(k,i,x);
// Updates array k position
// i to x

// seg.query(k,l,r)
// Returns the sum of a[l..r]
// in array k