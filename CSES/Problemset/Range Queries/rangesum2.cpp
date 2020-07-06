#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[200001];
ll segTree[1000000];

void build(int l, int r, int ind)
{
    if (l==r)
    {
        segTree[ind]=a[l];
        return;
    }
    build(l,l+(r-l)/2,ind*2+1);
    build(l+(r-l)/2+1,r,ind*2+2);
    segTree[ind]=segTree[ind*2+1]+segTree[ind*2+2];
}

void update(int l, int r, int x, int ind)
{
    if (x<l||r<x)
        return;
    if (l==r)
    {
        segTree[ind]=a[l];
        return;
    }
    update(l,l+(r-l)/2,x,ind*2+1);
    update(l+(r-l)/2+1,r,x,ind*2+2);
    segTree[ind]=segTree[ind*2+1]+segTree[ind*2+2];
}

ll sum(int curL, int curR, int l, int r, int ind)
{
    if (curR<l||r<curL)
        return 0;
    if (l<=curL&&curR<=r)
        return segTree[ind];
    return sum(curL,curL+(curR-curL)/2,l,r,ind*2+1)+sum(curL+(curR-curL)/2+1,curR,l,r,ind*2+2);
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
            cout<<sum(1,n,x,y,0)<<"\n";
    }
    return 0;
}