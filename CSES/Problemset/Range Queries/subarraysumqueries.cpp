#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mn = 2e5+1;
ll seg[mn<<2][4];

void recalc(int i)
{
    int l=(i<<1)+1,r=(i<<1)+2;
    seg[i][0]=seg[l][0]+seg[r][0];
    seg[i][1]=max({seg[l][0],seg[l][0]+seg[r][0],seg[l][0]+seg[r][1],seg[l][1]});
    seg[i][2]=max({seg[r][0],seg[r][0]+seg[l][0],seg[r][0]+seg[l][2],seg[r][2]});
    seg[i][3]=max({seg[i][0],seg[i][1],seg[i][2],seg[l][3],seg[r][3],seg[l][2]+seg[r][1]});
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        cin>>seg[i][0];
        seg[i][1]=seg[i][2]=seg[i][3]=seg[i][0];
        return;
    }
    build((i<<1)+1,l,(l+r)>>1);
    build((i<<1)+2,((l+r)>>1)+1,r);
    recalc(i);
}

void update(int i, int l, int r, int j, int x)
{
    if (r<j||j<l)
        return;
    if (l==r)
    {
        for (int k=0;k<4;++k)
            seg[i][k]=x;
        return;
    }
    update((i<<1)+1,l,(l+r)>>1,j,x);
    update((i<<1)+2,((l+r)>>1)+1,r,j,x);
    recalc(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y;
    cin>>n>>q;
    build(0,1,n);
    while (q--)
    {
        cin>>x>>y;
        update(0,1,n,x,y);
        cout<<max({seg[0][3],0LL})<<"\n";
    }
    return 0;
}