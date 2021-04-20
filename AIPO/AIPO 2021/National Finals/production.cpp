#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mn = 2e6+7, INF = 1e9+7;
int segTree[mn<<2][2],a[mn];

void build(int i, int l, int r)
{
    if (l==r)
    {
        segTree[i][0]=a[l];
        segTree[i][1]=a[l];
        return;
    }
    build((i<<1)+1,l,l+((r-l)>>1));
    build((i<<1)+2,l+((r-l)>>1)+1,r);
    segTree[i][0]=min(segTree[(i<<1)+1][0],segTree[(i<<1)+2][0]);
    segTree[i][1]=segTree[(i<<1)+1][1]+segTree[(i<<1)+2][1];
}

void update(int i, int cL, int cR, int j)
{
    if (j<cL||cR<j)
        return;
    if (cL==cR)
    {
        segTree[i][0]=INF;
        segTree[i][1]=0;
        return;
    }
    update((i<<1)+1,cL,cL+((cR-cL)>>1),j);
    update((i<<1)+2,cL+((cR-cL)>>1)+1,cR,j);
    segTree[i][0]=min(segTree[(i<<1)+1][0],segTree[(i<<1)+2][0]);
    segTree[i][1]=segTree[(i<<1)+1][1]+segTree[(i<<1)+2][1];
}

int sQuery(int i, int cL, int cR, int l, int r)
{
    if (r<cL||cR<l)
        return 0;
    if (l<=cL&&cR<=r)
        return segTree[i][1];
    return sQuery((i<<1)+1,cL,cL+((cR-cL)>>1),l,r)+sQuery((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r);
}

int minQuery(int i, int cL, int cR, int l, int r)
{
    if (r<cL||cR<l)
        return INF;
    if (l<=cL&&cR<=r)
        return segTree[i][0];
    return min(minQuery((i<<1)+1,cL,cL+((cR-cL)>>1),l,r),minQuery((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r));
}



struct BIT
{
    int n;
    vector<ll> bit;
    BIT(int n) : n(n), bit(n+1) {}
    void update(int i, ll d)
    {
        while (i<=n)
        {
            bit[i]+=d;
            i+=(i&-i);
        }
    }
    ll query(int i)
    {
        if (i<=0)
            return 0;
        ll ret = 0;
        while (i)
        {
            ret+=bit[i];
            i-=(i&-i);
        }
        return ret;
    }
    ll query(int l, int r)
    {
        return query(r)-query(l-1);
    }
};

int n;

int findInd(int k, BIT &bit)
{
    int r = n;
    for (int i=23;i>=0;--i)
        if (r-(1<<i)>0&&bit.query(r-(1<<i))>=k)
            r-=(1<<i);
    return r;
}

void makeQuery(int l, int r)
{
    cout<<sQuery(0,1,n,l,r)<<" "<<minQuery(0,1,n,l,r)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,l,r;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    build(0,1,n);
    BIT bit(n+5);
    for (int i=1;i<=n;++i)
        bit.update(i,1);
    cin>>q;
    char c;
    int x,y;
    for (int i=0;i<q;++i)
    {
        cin>>c;
        if (c=='F')
        {
            cin>>x;
            x=findInd(x+1,bit);
            bit.update(x,-1);
            update(0,1,n,x);
        }
        else if (c=='Q')
        {
            cin>>x>>y;
            l=findInd(x+1,bit);
            r=findInd(y+1,bit);
            makeQuery(l,r);
        }
        else
        {
            cin>>x;
            x=findInd(x+1,bit);
            if ((x>1&&bit.query(x-1,x-1)==0)||(x<n&&bit.query(x+1,x+1)==0))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}