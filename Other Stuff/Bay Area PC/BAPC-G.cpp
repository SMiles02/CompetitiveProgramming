#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define f first
#define s second
#define pll pair<ll,ll>
using namespace std;
 
const int MAXN=3e5+10;
pair<ll,pll> segTree[MAXN<<2]; //{val,{add,change}}
int lenOf[MAXN],a[MAXN];
ll ans;
 
ll getVal(int i)
{
    if (segTree[i].s.s)
        return (segTree[i].s.s+segTree[i].s.f)*lenOf[i];
    return segTree[i].f+(segTree[i].s.f*lenOf[i]);
}
 
void calc(int i)
{
    if (segTree[i].s.s)
        return;
    segTree[i].f=getVal((i<<1)+1)+getVal((i<<1)+2);
}
 
void passDown(int i)
{
    if (segTree[i].s.s)
    {
        segTree[(i<<1)+1].s.f=0;
        segTree[(i<<1)+2].s.f=0;
        segTree[(i<<1)+1].s.s=segTree[i].s.s+segTree[i].s.f;
        segTree[(i<<1)+2].s.s=segTree[i].s.s+segTree[i].s.f;
    }
    else
    {
        segTree[(i<<1)+1].s.f+=segTree[i].s.f;
        segTree[(i<<1)+2].s.f+=segTree[i].s.f;
    }
    segTree[i].s.f=0;
    segTree[i].s.s=0;
    calc(i);
}
 
void build(int i, int l, int r)
{
    lenOf[i]=r-l+1;
    if (l==r)
    {
        segTree[i].f=a[l];
        return;
    }
    int m=l+((r-l)>>1);
    build((i<<1)+1,l,m);
    build((i<<1)+2,m+1,r);
    calc(i);
}
 
void update(int i, int cL, int cR, int l, int r, int x, int y)
{
    if (r<cL||cR<l)
        return;
    if (l<=cL&&cR<=r)
    {
        if (y)
        {
            segTree[i].s.f=0;
            segTree[i].s.s=y;
        }
        else
            segTree[i].s.f+=x;
        return;
    }
    passDown(i);
    int m=cL+((cR-cL)>>1);
    update((i<<1)+1,cL,m,l,r,x,y);
    update((i<<1)+2,m+1,cR,l,r,x,y);
    calc(i);
}
 
void query(int i, int cL, int cR, int l, int r)
{
    if (r<cL||cR<l)
        return;
    if (l<=cL&&cR<=r)
    {
        ans+=getVal(i);
        return;
    }
    passDown(i);
    int m=cL+((cR-cL)>>1);
    query((i<<1)+1,cL,m,l,r);
    query((i<<1)+2,m+1,cR,l,r);
    calc(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin>>n>>q;
    int b[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    map<int,int> m;
    sort(a+1,a+n+1);

    return 0;
}