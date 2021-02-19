#include <bits/stdc++.h>
using namespace std;

struct implicit {
    struct node {
        int val = 0;
        node *l, *r;
    };
    deque<node> buffer;
    node *newnode() {
        buffer.emplace_back();
        return &buffer.back();
    }
    int n;
    node *root;
    implicit(int n) : n(n) {root = newnode();}
    void update(node *&v, int l, int r, int i, int x) {
        if (i<l||r<i)
            return;
        if (!v) 
            v=newnode();
        v->val+=x;
        if (l==r)
            return;
        update(v->l,l,(l+r)>>1,i,x);
        update(v->r,(l+r+2)>>1,r,i,x);
    }
    void update(int i, int x) {
        update(root, 1, n, i, x);
    }
    int query(node* v, int cL, int cR, int l, int r) {
        if (r<cL||cR<l||!v)
            return 0;
        if (l<=cL&&cR<=r)
            return v->val;
        return query(v->l,cL,(cL+cR)>>1,l,r) + query(v->r,(cL+cR+2)>>1,cR,l,r);
    }
    int query(int l, int r) {
        return query(root,1,n,l,r);
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y;
    char c;
    cin>>n>>q;
    int a[n+1];
    implicit seg(1000000000);
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        seg.update(a[i],1);
    }
    while (q--)
    {
        cin>>c>>x>>y;
        if (c=='?')
            cout<<seg.query(x,y)<<"\n";
        else
        {
            seg.update(a[x],-1);
            seg.update(y,1);
            a[x]=y;
        }
    }
    return 0;
}