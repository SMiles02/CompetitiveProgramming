#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct implicit
{
    struct node
    {
        node *l,*r;
        int val = 0;
        bool allSet = 0;
    };
    deque<node> buffer;
    int n;
    node *root;
    node *newnode()
    {
        buffer.emplace_back();
        return &buffer.back();
    }
    implicit(int n) : n(n) {root=newnode();}
    void passDown(node *&v)
    {
        if (!(v->l))
            v->l=newnode();
        if (!(v->r))
            v->r=newnode();
        if (v->allSet)
        {
            v->l->allSet=1;
            v->r->allSet=1;
        }
    }
    int calc(node *&v, int l, int r)
    {
        if (v->allSet)
            return r-l+1;
        return v->val;
    }
    void update(node *&v, int cL, int cR, int l, int r)
    {
        if (r<cL||cR<l)
            return;
        if (l<=cL&&cR<=r)
        {
            v->allSet=1;
            return;
        }
        passDown(v);
        update(v->l,cL,cL+(cR-cL)/2,l,r);
        update(v->r,cL+(cR-cL)/2+1,cR,l,r);
        v->val=calc(v->l,cL,cL+(cR-cL)/2)+calc(v->r,cL+(cR-cL)/2+1,cR);
    }
    void update(int l, int r)
    {
        update(root,1,n,l,r);
    }
    int query(node *&v, int cL, int cR, int l, int r)
    {
        if (r<cL||cR<l)
            return 0;
        if (l<=cL&&cR<=r)
            return calc(v,cL,cR);
        passDown(v);
        int rtn = query(v->l,cL,cL+(cR-cL)/2,l,r) + query(v->r,cL+(cR-cL)/2+1,cR,l,r);
        v->val=calc(v->l,cL,cL+(cR-cL)/2)+calc(v->r,cL+(cR-cL)/2+1,cR);
        return rtn;
    }
    int query(int l, int r)
    {
        return query(root,1,n,l,r);
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,d,x,y,c=0;
    cin>>n;
    implicit seg(1e9);
    while (n--)
    {
        cin>>d>>x>>y;
        if (d==1)
        {
            c=seg.query(x+c,y+c);
            cout<<c<<"\n";
        }
        else
            seg.update(x+c,y+c);
    }
    return 0;
}