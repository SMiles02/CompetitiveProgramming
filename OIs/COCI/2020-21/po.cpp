#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+7, INF = 1e9+7;
int n,segTree[mn<<2],lazy[mn<<2],ans;

int val(int i)
{
    return segTree[i] + lazy[i];
}

void recalc(int i)
{
    segTree[i]=min(val((i<<1)+1),val((i<<1)+2));
}

void passDown(int i)
{
    lazy[(i<<1)+1]+=lazy[i];
    lazy[(i<<1)+2]+=lazy[i];
    lazy[i]=0;
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        cin>>segTree[i];
        return;
    }
    build((i<<1)+1,l,l+((r-l)>>1));
    build((i<<1)+2,l+((r-l)>>1)+1,r);
    segTree[i]=min(segTree[(i<<1)+1],segTree[(i<<1)+2]);
}

void update(int i, int cL, int cR, int l, int r, int x)
{
    if (r<cL||cR<l)
        return;
    if (l<=cL&&cR<=r)
    {
        lazy[i]+=x;
        return;
    }
    passDown(i);
    update((i<<1)+1,cL,cL+((cR-cL)>>1),l,r,x);
    update((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r,x);
    recalc(i);
}

void query(int i, int cL, int cR, int l, int r)
{
    //cout<<i<<" "<<cL<<" "<<cR<<" "<<l<<" "<<r<<"\n";
    if (r<cL||cR<l)
        return;
    if (l<=cL&&cR<=r)
    {
        ans=min(ans,val(i));
        return;
    }
    passDown(i);
    query((i<<1)+1,cL,cL+((cR-cL)>>1),l,r);
    query((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r);
    recalc(i);
}

int f(int L, int R)
{
    //cout<<L<<" "<<R<<"\n";
    if (R<L)
        return 0;
    int rV=0,l,r,m;
    ans=INF;
    query(0,1,n,L,R);
    if (ans)
    {
        ++rV;
        update(0,1,n,L,R,-ans);
    }
    ans=0;
    while (ans==0&&L<=R)
    {
        ans=INF;
        query(0,1,n,L,L);
        if (ans==0)
            ++L;
    }
    ans=0;
    while (ans==0&&L<=R)
    {
        ans=INF;
        query(0,1,n,R,R);
        if (ans==0)
            --R;
    }
    if (R<L)
        return rV;
    l=L;r=R;
    while (l^r)
    {
        m=l+(r-l)/2+1;
        ans=INF;
        query(0,1,n,L,m);
        if (ans==0)
            r=m-1;
        else
            l=m;
    }
    return rV + f(L,l) + f(l+1,R);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    build(0,1,n);
    cout<<f(1,n);
    return 0;
}