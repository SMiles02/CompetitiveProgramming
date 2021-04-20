#include <bits/stdc++.h>
using namespace std;

struct pst {
    struct node {
        int val;
        node *l, *r;
        node(ll x) : val(x) {}
    };
    deque<node> buffer;
    node *newnode(int x = 0) {
        buffer.emplace_back(x);
        return &buffer.back();
    }
    node *merge(node *l, node *r) {
        auto x = newnode(l->val + r->val);
        x->l = l, x->r = r;
        return x;
    }
    int n, a=0;
    node *roots[200005];
    pst(int n) : n(n) {roots[0] = build(1, n);}
    node *build(int l, int r) {
        if(l == r) 
            return newnode();
        return merge(build(l,(l+r)>>1),build((l+r+2)>>1, r));
    }
    node *update(node *v, int l, int r, int i, int x) {
        if(r < i || i < l)
            return v;
        if(l == r)
            return newnode(v->val+x);
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
    int n,q,x,L,R,l,r,m;
    cin>>n>>q;
    pst seg(n);
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        seg.clone(i-1);
        seg.update(i,x,1);
    }
    while (q--)
    {
        cin>>L>>R;
        l=1;r=n;
        while (l<r)
        {
            m=l+(r-l)/2+1;
            x = seg.query(R,m,n) - seg.query(L-1,m,n);
            if (x<m)
                r=m-1;
            else
                l=m;
        }
        cout<<l<<"\n";
    }
    return 0;
}