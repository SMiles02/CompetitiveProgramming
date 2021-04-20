#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

struct pst
{
    struct node
    {
        node *l,*r;
        int x = 0;
    };
    int n;
    node* root;
    deque<node> buffer;
    node* newnode()
    {
        return &buffer.emplace_back();
    }
    int t = 0;
    pst(int n) : n(n) {root=newnode();}
    int query(node* v, int cL, int cR, int x)
    {
        if (x<=cL||!v)
            return 0;
        if (cR<x)
            return v->x;
        return add(query(v->l,cL,cL+(cR-cL)/2,x),query(v->r,cL+(cR-cL)/2+1,cR,x));
    }
    int query(int x)
    {
        return query(root,1,n,x);
    }
    void update(node *&v, int cL, int cR, int x, int y)
    {
        if (x<cL||cR<x)
            return;
        if (!v)
            v=newnode();
        v->x=add(v->x,y);
        if (cL==cR)
            return;
        update(v->l,cL,cL+(cR-cL)/2,x,y);
        update(v->r,cL+(cR-cL)/2+1,cR,x,y);
    }
    void update(int x, int y)
    {
        update(root,1,n,x,y);
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,ans=0,c;
    cin>>n;
    pst seg(1e9);
    for (int i=0;i<n;++i)
    {
        cin>>x;
        c=seg.query(x)+1;
        seg.update(x,c);
        ans=add(ans,c);
    }
    cout<<ans;
    return 0;
}