#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const ll zero = 0;
const int mod = 1e9;
ll g,h;

ll calc(ll x, ll a, ll b)
{
    return (x*a)+b;
}

struct node
{
    node *l, *r;
    ll a, b;
    node(ll p, ll q) : l(nullptr), r(nullptr), a(p), b(q) {}
    node(node *l1, node *r1) : l(l1), r(r1), a(0), b(0) {}
    node(ll p, ll q, node *l1, node *r1) : l(l1), r(r1), a(p), b(q) {}
};

node* build(int cL, int cR)
{
    if (cL==cR)
        return new node(zero,zero);
    int cM = cL + ((cR-cL)>>1);
    return new node(build(cL,cM),build(cM+1,cR));
}

node* update(node* nd, int cL, int cR, int x1, int x2, int y1, int a, int b, int y2)
{
    if (cR<=x1)
        return new node(nd->a,nd->b+y1,nd->l,nd->r);
    if (x2<cL)
        return new node(nd->a,nd->b+y2,nd->l,nd->r);
    if (x1<cL&&cR<=x2)
        return new node(nd->a+a,nd->b+b,nd->l,nd->r);
    int cM = cL + ((cR-cL)>>1);
    return new node(nd->a,nd->b,update(nd->l,cL,cM,x1,x2,y1,a,b,y2),update(nd->r,cM+1,cR,x1,x2,y1,a,b,y2));
}

void query(node* nd, int cL, int cR, int x)
{
    if (x<cL||cR<x)
        return;
    g+=nd->a;
    h+=nd->b;
    if (cL==cR)
        return;
    int cM = cL + ((cR - cL)>>1);
    query(nd->l,cL,cM,x);
    query(nd->r,cM+1,cR,x);
}

node* roots[75001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x1,x2,y1,y2,a,b,l,r;
    ll cur=0,last=0,x;
    cin>>n;
    roots[0]=build(0,200001);
    for (int i=1;i<=n;++i)
    {
        cin>>x1>>x2>>y1>>a>>b>>y2;
        roots[i]=update(roots[i-1],0,200001,x1,x2,y1,a,b,y2);
    }
    cin>>m;
    while (m--)
    {
        cin>>l>>r>>x;
        x+=last;
        x%=mod;
        g=0;h=0;
        if (x>200000)
            query(roots[r],0,200001,200001);
        else
            query(roots[r],0,200001,x);
        cur=calc(x,g,h);
        g=0;h=0;
        if (x>200000)
            query(roots[l-1],0,200001,200001);
        else
            query(roots[l-1],0,200001,x);
        cur-=calc(x,g,h);
        cout<<cur<<"\n";
        last=cur;
    }
    return 0;
}