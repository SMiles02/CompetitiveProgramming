#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2e5+7, INF = 1e9+7;
int segTree[mn<<2];

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

void update(int i, int cL, int cR, int j, int x)
{
    if (j<cL||cR<j)
        return;
    if (cL==cR)
    {
        segTree[i]=x;
        return;
    }
    update((i<<1)+1,cL,cL+((cR-cL)>>1),j,x);
    update((i<<1)+2,cL+((cR-cL)>>1)+1,cR,j,x);
    segTree[i]=min(segTree[(i<<1)+1],segTree[(i<<1)+2]);
}

int query(int i, int cL, int cR, int l, int r)
{
    if (r<cL||cR<l)
        return INF;
    if (l<=cL&&cR<=r)
        return segTree[i];
    return min(query((i<<1)+1,cL,cL+((cR-cL)>>1),l,r),query((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r));
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,t,l,r;
    cin>>n>>q;
    build(0,1,n);
    while (q--)
    {
        cin>>t>>l>>r;
        if (t==1)
            update(0,1,n,l,r);
        else
            cout<<query(0,1,n,l,r)<<"\n";
    }
    return 0;
}