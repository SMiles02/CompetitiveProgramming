#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int segtree[4000005];

void update(int l, int r, int curL, int curR, int i, int x)
{
    if (l<=curL&&curR<=r)
    {
        segtree[i]+=x;
        return;
    }
    if (curR<l||r<curL)
        return;
    update(l,r,curL,curL+(curR-curL)/2,i*2+1,x);
    update(l,r,curL+(curR-curL)/2+1,curR,i*2+2,x);
}

int value(int curL, int curR, int x, int i)
{
    if (x<curL||curR<x)
        return 0;
    if (curL==x&&curR==x)
        return segtree[i];
    return segtree[i]+value(curL,curL+(curR-curL)/2,x,i*2+1)+value(curL+(curR-curL)/2+1,curR,x,i*2+2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,k,l,r,m;
    cin>>n>>q;
    while (n--)
    {
        cin>>k;
        cout<<"add "<<1000000-n<<": "<<k<<"\n";
        update(k,1000000,1,1000000,0,1);
    }
    while (q--)
    {
        cin>>k;
        if (k>0)
        {
            update(k,1000000,1,1000000,0,1);
            continue;
        }
        k*=-1;
        l=1,r=1000000;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (value(1,1000000,m,0)<k)
                l=m+1;
            else
                r=m;
        }
        update(l,1000000,1,1000000,0,-1);
    }
    if (value(1,1000000,1000000,0)>0)
    {
        l=1,r=1000000;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (value(1,1000000,m,0))
                r=m;
            else
                l=m+1;
        }
        cout<<l;
    }
    else
        cout<<0;
    return 0;
}