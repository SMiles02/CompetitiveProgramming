//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

template<class T> struct Implicit {
    // merge(ID,x) = x
    // range [0,n]
    const T ID = 0;
    T merge(T a, T b) { return a+b; }
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
    int n,q,x,y,t,k;
    cin>>n>>q;
    cin>>x>>y;
    Implicit<int> seg(2e9);
    set<int> s;
    while (q--)
    {
        cin>>t>>k;
        if (t==1)
        {
            if (s.count(k))
                seg.update(k%(x+y),-1);
            else
                seg.update(k&(x+y),1);
        }
        else
        {

        }
    }
    return 0;
}