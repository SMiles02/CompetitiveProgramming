#include <bits/stdc++.h>
using namespace std;

struct implicit
{
    struct node
    {
        int x = 0;
        node *l, *r;
    };
    deque<node> buffer;
    node *newnode()
    {
        buffer.emplace_back();
        return &buffer.back();
    }
    int n;
    node *root;
    implicit(int n) : n(n) {root=newnode();}
    void update(node *&v, int l, int r, int qL, int qR, int x)
    {
        if (qR<l||r<qL)
            return;
        if (!v)
            v=newnode();
        if (qL<=l&&r<=qR)
        {
            v->x=max(v->x,x);
            return;
        }
        update(v->l,l,l+(r-l)/2,qL,qR,x);
        update(v->r,l+(r-l)/2+1,r,qL,qR,x);
    }
    void update(int l, int r, int x)
    {
        if (l<=r)
            update(root,1,n,l,r,x);
    }
    int query(node *v, int l, int r, int x)
    {
        if (x<l||r<x||!v)
            return 0;
        if (l==r)
            return v->x;
        return max({v->x,query(v->l,l,l+(r-l)/2,x),query(v->r,l+(r-l)/2+1,r,x)});
    }
    int query(int x)
    {
        return query(root,1,n,x);
    }
};
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y,z,ans;
    cin>>n>>q;
    char c;
    implicit a(n),b(n);
    while (q--)
    {
        cin>>x>>y>>c;
        if (c=='L')
        {
            z=b.query(y);
            ans=x-z;
            a.update(z+1,x,y);
            b.update(y,y,x);
        }
        else
        {
            z=a.query(x);
            ans=y-z;
            a.update(x,x,y);
            b.update(z+1,y,x);
        }
        cout<<ans<<"\n";
    }
    return 0;
}