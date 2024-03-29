#include <bits/stdc++.h>
#define ll long long
using namespace std;

template<class T> struct Implicit {
    // merge(ID,x) = x
    // range [0,n]
    const T ID = 0;
    T merge(T a, T b) { return max(a,b); }
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
    Implicit(int n) : n(n) {root = newnode();}
    void update(node *&v, int l, int r, int i, T x) {
        if (i<l||r<i)
            return;
        if (!v) 
            v=newnode();
        v->val=merge(v->val,x);
        if (l==r)
            return;
        update(v->l,l,(l+r)>>1,i,x);
        update(v->r,(l+r+2)>>1,r,i,x);
    }
    void update(int i, T x) {
        update(root, 0, n, i, x);
    }
    T query(node* v, int cL, int cR, int l, int r) {
        if (r<cL||cR<l||!v)
            return ID;
        if (l<=cL&&cR<=r)
            return v->val;
        return merge(query(v->l,cL,(cL+cR)>>1,l,r), query(v->r,(cL+cR+2)>>1,cR,l,r));
    }
    T query(int l, int r) {
        return query(root,0,n,l,r);
    }
};
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int h[n], a[n];
    Implicit<ll> st(1e9);
    for (int i=0;i<n;++i)
        cin>>h[i];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        st.update(h[i],st.query(0,h[i])+a[i]);
    }
    cout<<st.query(0,1e9);
    return 0;
}