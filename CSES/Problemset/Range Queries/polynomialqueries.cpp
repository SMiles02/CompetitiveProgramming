#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2e5+1;
ll seg[mn<<2],lazy[mn<<2][2],rg[mn<<2],ans;

ll f(ll x, ll y, ll z)
{
    return x*z+((z*(z-1))/2)*y;
}

void passDown(int i)
{
    lazy[2*i+1][0]+=lazy[i][0];
    lazy[2*i+1][1]+=lazy[i][1];
    lazy[2*i+2][0]+=lazy[i][0]+lazy[i][1]*rg[i*2+1];
    lazy[2*i+2][1]+=lazy[i][1];
    lazy[i][0]=0;
    lazy[i][1]=0;
}

ll val(int i)
{
    return seg[i]+f(lazy[i][0],lazy[i][1],rg[i]);
}

void recalc(int i)
{
    seg[i]=val(i*2+1)+val(i*2+2);
}

void build(int i, int l, int r)
{
    rg[i]=r-l+1;
    if (l==r)
    {
        cin>>seg[i];
        return;
    }
    build(i*2+1,l,(l+r)>>1);
    build(i*2+2,(l+r+2)>>1,r);
    seg[i]=seg[i*2+1]+seg[i*2+2];
}

void update(int i, int cL, int cR, int l, int r)
{
    if (cR<l||r<cL)
        return;
    if (l<=cL&&cR<=r)
    {
        lazy[i][0]+=cL-l+1;
        ++lazy[i][1];
        return;
    }
    passDown(i);
    update(i*2+1,cL,(cL+cR)>>1,l,r);
    update(i*2+2,(cL+cR+2)>>1,cR,l,r);
    recalc(i);
}

void query(int i, int cL, int cR, int l, int r)
{
    if (cR<l||r<cL)
        return;
    if (l<=cL&&cR<=r)
    {
        ans+=val(i);
        return;
    }
    passDown(i);
    query(i*2+1,cL,(cL+cR)>>1,l,r);
    query(i*2+2,(cL+cR+2)>>1,cR,l,r);
    recalc(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,k,l,r;
    cin>>n>>q;
    build(0,1,n);
    while (q--)
    {
        cin>>k>>l>>r;
        if (k==1)
            update(0,1,n,l,r);
        else
        {
            ans=0;
            query(0,1,n,l,r);
            cout<<ans<<"\n";
        }
    }
    return 0;
}