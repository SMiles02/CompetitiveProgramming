#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,segTree[1000000],a[200001];

void build(int i, int l, int r)
{
    if (l==r)
    {
        segTree[i]=l;
        return;
    }
    build((i<<1),l,((l+r)>>1));
    build((i<<1)+1,((l+r)>>1)+1,r);
}

int query(int i, int l, int r, int x)
{
    if (x<l||r<x)
        return 0;
    if (l==r)
        return segTree[i];
    return segTree[i]+query((i<<1),l,((l+r)>>1),x)+query((i<<1)+1,((l+r)>>1)+1,r,x);
}

void update(int i, int l, int r, int x, int y) //update x-y, currently at -1
{
    if (r<x||y<l)
        return;
    if (x<=l&&r<=y)
    {
        --segTree[i];
        return;
    }
    update((i<<1),l,((l+r)>>1),x,y);
    update((i<<1)+1,((l+r)>>1)+1,r,x,y);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,l,r,m;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    build(1,1,n);
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        l=1,r=n;
        while (l<r)
        {
            m=l+(r-l)/2+1;
            if (query(1,1,n,m)>k)
                r=m-1;
            else
                l=m;
        }
        cout<<a[l]<<" ";
        update(1,1,n,l+1,n);
    }
    return 0;
}