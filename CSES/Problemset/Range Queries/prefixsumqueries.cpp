#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mn = 2e5+1;
int n,x,y;
ll seg[mn<<2][2],tot,pre;

void recalc(int i)
{
    seg[i][0]=seg[i*2+1][0]+seg[i*2+2][0];
    seg[i][1]=max({seg[i*2+1][1],seg[i*2+1][0]+seg[i*2+2][1]});
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        if (l==0)
            return;
        cin>>seg[i][0];
        seg[i][1]=seg[i][0];
        return;
    }
    build(i*2+1,l,(l+r)>>1);
    build(i*2+2,(l+r+2)>>1,r);
    recalc(i);
}

void update(int i, int l, int r)
{
    if (x<l||r<x)
        return;
    if (l==r)
    {
        seg[i][0]=seg[i][1]=y;
        return;
    }
    update(i*2+1,l,(l+r)>>1);
    update(i*2+2,(l+r+2)>>1,r);
    recalc(i);
}

void query(int i, int cL, int cR)
{
    if (y<cL||cR<x)
        return;
    if (x<=cL&&cR<=y)
    {
        pre=max({pre,tot+seg[i][1]});
        tot+=seg[i][0];
        return;
    }
    query(i*2+1,cL,(cL+cR)>>1);
    query(i*2+2,(cL+cR+2)>>1,cR);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,k;
    cin>>n>>q;
    build(0,1,n);
    while (q--)
    {
        cin>>k>>x>>y;
        if (k==1)
            update(0,1,n);
        else
        {
            tot=pre=0;
            query(0,1,n);
            cout<<pre<<"\n";
        }
    }
    return 0;
}