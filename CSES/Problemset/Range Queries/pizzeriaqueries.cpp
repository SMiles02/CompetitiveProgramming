#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mn = 2e5+1, INF = 2e9;
int seg[mn<<2][2];

void build(int i, int l, int r)
{
    if (l==r)
    {
        cin>>seg[i][0];
        seg[i][1]=seg[i][0]+l;
        seg[i][0]-=l;
        return;
    }
    build((i<<1)+1,l,(l+r)>>1);
    build((i<<1)+2,((l+r)>>1)+1,r);
    seg[i][0]=min(seg[(i<<1)+1][0],seg[(i<<1)+2][0]);
    seg[i][1]=min(seg[(i<<1)+1][1],seg[(i<<1)+2][1]);   
}

void update(int i, int l, int r, int j, int x)
{
    if (j<l||r<j)
        return;
    if (l==r)
    {
        seg[i][0]=x-l;
        seg[i][1]=x+l;
        return;
    }
    update((i<<1)+1,l,(l+r)>>1,j,x);
    update((i<<1)+2,((l+r)>>1)+1,r,j,x);
    seg[i][0]=min(seg[(i<<1)+1][0],seg[(i<<1)+2][0]);
    seg[i][1]=min(seg[(i<<1)+1][1],seg[(i<<1)+2][1]);   
}

int query(int i, int cL, int cR, int l, int r, int j)
{
    if (r<cL||cR<l)
        return INF;
    if (l<=cL&&cR<=r)
        return seg[i][j];
    return min(query((i<<1)+1,cL,(cL+cR)>>1,l,r,j),query((i<<1)+2,((cL+cR)>>1)+1,cR,l,r,j));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,t,k,x;
    cin>>n>>q;
    build(0,1,n);
    while (q--)
    {
        cin>>t;
        if (t==1)
        {
            cin>>k>>x;
            update(0,1,n,k,x);
        }
        else
        {
            cin>>k;
            cout<<min(k+query(0,1,n,1,k,0),query(0,1,n,k,n,1)-k)<<"\n";
        }
    }
    return 0;
}