#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

const int mn = 3e5+7, INF = 1e9+7;
int segTree[mn<<2][2],p[mn],n;
ll b[mn];

void build(int i, int l, int r)
{
    if (l==r)
    {
        cin>>segTree[i][0];
        segTree[i][1]=segTree[i][0];
        p[segTree[i][0]]=l;
        return;
    }
    build((i<<1)+1,l,l+((r-l)>>1));
    build((i<<1)+2,l+((r-l)>>1)+1,r);
    segTree[i][0]=min(segTree[(i<<1)+1][0],segTree[(i<<1)+2][0]);
    segTree[i][1]=max(segTree[(i<<1)+1][1],segTree[(i<<1)+2][1]);
}

int query(int i, int cL, int cR, int l, int r, int j)
{
    if (r<cL||cR<l)
    {
        if (j==0)
            return INF;
        return 0;
    }
    if (l<=cL&&cR<=r)
        return segTree[i][j];
    if (j==0)
        return min(query((i<<1)+1,cL,cL+((cR-cL)>>1),l,r,0),query((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r,0));
    return max(query((i<<1)+1,cL,cL+((cR-cL)>>1),l,r,1),query((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r,1));
}

int query(int l, int r, int j)
{
    return query(0,1,n,l,r,j);
}

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

ll f(int l, int r)
{
    if (l>r)
        return 0;
    //cout<<l<<" "<<r<<"\n";
    if (l==r)
        return b[l];
    int x = query(l,r,1),y;
    y=p[x];
    ll val = max(max(b[y],0)+f(l,y-1)+f(y+1,r),b[p[query(l,r,0)]]);
    cout<<l<<" "<<r<<": "<<val<<"\n";
    return val;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    build(0,1,n);
    for (int i=1;i<=n;++i)
        cin>>b[i];
    cout<<f(1,n);
    return 0;
}