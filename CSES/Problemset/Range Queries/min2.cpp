#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[200001];
int segTree[1000000];

void build(int l, int r, int i)
{
    if (l==r)
    {
        segTree[i]=a[l];
        return;
    }
    build(l,l+(r-l)/2,i*2+1);
    build(l+(r-l)/2+1,r,i*2+2);
    segTree[i]=min(segTree[i*2+1],segTree[i*2+2]);
}

void update(int l, int r, int x, int i)
{
    if (x<l||r<x)
        return;
    if (l==r)
    {
        segTree[i]=a[x];
        return;
    }
    update(l,l+(r-l)/2,x,i*2+1);
    update(l+(r-l)/2+1,r,x,i*2+2);
    segTree[i]=min(segTree[i*2+1],segTree[i*2+2]);
}

int query(int curL, int curR, int l, int r, int i)
{
    if (r<curL||curR<l)
        return 1000000000;
    if (l<=curL&&curR<=r)
        return segTree[i];
    return min(query(curL,curL+(curR-curL)/2,l,r,i*2+1),query(curL+(curR-curL)/2+1,curR,l,r,i*2+2));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,k,x,y;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    build(1,n,0);
    while (q--)
    {
        cin>>k>>x>>y;
        if (k==1)
        {
            a[x]=y;
            update(1,n,x,0);
        }
        else
            cout<<query(1,n,x,y,0)<<"\n";
    }
    return 0;
}