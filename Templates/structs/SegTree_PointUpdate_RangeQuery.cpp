template<class T> struct Segtree {
    // merge(ID,x) = x
    // range [0,n]
    const T ID = 0;
    int n;
    vector<T> v;
    Segtree(int n) : n(n), v(n*4+4, ID) {}
    T merge(T a, T b) { return max(a,b); }
    void update(int i, int l, int r, int j, T x) {
        if (j<l||r<j)
            return;
        if (l==r) {
            v[i]=x;
            return;
        }
        int m=l+(r-l)/2;
        if (j<=m)
            update(i*2+1,l,m,j,x);
        else
            update(i*2+2,m+1,r,j,x);
        v[i]=merge(v[i*2+1],v[i*2+2]);
    }
    void update(int i, T x) { update(0,0,n,i,x); }
    T query(int i, int l, int r, int qL, int qR) {
        if (r<qL||qR<l)
            return ID;
        if (qL<=l&&r<=qR)
            return v[i];
        int m=l+(r-l)/2;
        return merge(query(i*2+1,l,m,qL,qR),query(i*2+2,m+1,r,qL,qR));
    }
    T query(int l, int r) { return query(0,0,n,l,r); }
};