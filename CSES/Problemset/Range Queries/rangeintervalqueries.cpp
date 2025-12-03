#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

template<class T> struct PST {
    // merge(ID,x) = x
    // range [0,n]
    T merge(T a, T b) { return a+b; }
    struct node {
        T val;
        node *l, *r;
        node(T x) : val(x) {}
    };
    deque<node> buffer;
    node *newnode(T x = 0) {
        buffer.emplace_back(x);
        return &buffer.back();
    }
    node *newnode(node *l, node *r) {
        auto x = newnode(merge(l->val,r->val));
        x->l = l, x->r = r;
        return x;
    }
    int n, a = 0;
    node *roots[200005];
    PST(int n) : n(n) {roots[0] = build(0, n);}
    node *build(int l, int r) {
        if(l == r) 
            return newnode(0);
        return newnode(build(l,(l+r)>>1),build((l+r+2)>>1, r));
    }
    node *update(node *v, int l, int r, int i, T x) {
        if(r < i || i < l)
            return v;
        if(l == r) {
            return newnode(x + v->val);
        }
        return newnode(update(v->l,l,(l+r)>>1,i,x), update(v->r,(l+r+2)>>1,r,i,x));
    }
    void update(int k, int i, T x) { roots[k] = update(roots[k], 0, n, i, x); }
    T query(node *v, int cL, int cR, int l, int r) {
        if (r<cL||cR<l)
            return 0;
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> x(n), y(n + q * 2);
    vector<array<int, 4>> queries(q);
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        y[i] = x[i];
    }
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> queries[i][j];
        }
        y[n + i * 2] = queries[i][2];
        y[n + i * 2 + 1] = queries[i][3];
    }
    sort(y.begin(), y.end());
    for (int i = 1; i < n + q * 2; ++i) {
        if (y[i] != y[i - 1]) {
            m[y[i]] = m[y[i - 1]] + 1;
        }
    }
    PST<int> segtree(n + q * 2 + 5);
    for (int i = 0; i < n; ++i) {
        segtree.clone(i);
        segtree.update(i + 1, m[x[i]], 1);
    }
    for (int i = 0; i < q; ++i) {
        cout << segtree.query(queries[i][1], m[queries[i][2]], m[queries[i][3]]) - segtree.query(queries[i][0] - 1, m[queries[i][2]], m[queries[i][3]]) << "\n";
    }
    return 0;
}