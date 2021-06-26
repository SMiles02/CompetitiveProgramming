#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[200001];

struct pst {
    struct node {
        ll val;
        node *l, *r;
        node(ll x) : val(x) {}
    };
    deque<node> buffer;
    node *newnode(ll x = 0) {
        buffer.emplace_back(x);
        return &buffer.back();
    }
    node *merge(node *l, node *r) {
        auto x = newnode(l->val + r->val);
        x->l = l, x->r = r;
        return x;
    }
    int n, a=1;
    node *roots[200005];
    pst(int n) : n(n) {roots[1] = build(1, n);}
    node *build(int l, int r) {
        if(l == r) 
            return newnode(arr[l]);
        return merge(build(l,(l+r)>>1),build((l+r+2)>>1, r));
    }
    node *update(node *v, int l, int r, int i, int x) {
        if(r < i || i < l)
            return v;
        if(l == r)
            return newnode(x);
        return merge(update(v->l,l,(l+r)>>1,i,x), update(v->r,(l+r+2)>>1,r,i,x));
    }
    void update(int k, int i, int x) {
        roots[k] = update(roots[k], 1, n, i, x);
    }
    ll query(node *v, int cL, int cR, int l, int r) {
        if (r<cL||cR<l)
            return 0;
        if (l<=cL&&cR<=r)
            return v->val;
        return query(v->l,cL,(cL+cR)>>1,l,r) + query(v->r,(cL+cR+2)>>1,cR,l,r);
    }
    ll query(int k, int l, int r) {
        return query(roots[k],1,n,l,r);
    }
    void clone(int k) {
        roots[++a] = merge(roots[k]->l, roots[k]->r);
        roots[a]->val = roots[k]->val;
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
        cin>>arr[i];
    pst seg(n);
    // seg.clone(k);
    // Creates a copy of k at
    // the newest position.

    // seg.update(k,i,x);
    // Updates array k position
    // i to x

    // seg.query(k,l,r)
    // Returns the sum of a[l..r]
    // in array k
    return 0;
}