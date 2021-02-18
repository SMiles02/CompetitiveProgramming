#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mn = 2e5+4;
const ll INF = -1e17;
ll seg[mn*4][9],lazy[mn*4];

ll f(int i, int j)
{
    if (j==0||j==6||j==7)
        return seg[i][j];
    if (j==2||j==4)
        return seg[i][j]+lazy[i];
    if (j==1||j==3)
        return seg[i][j]-lazy[i];
    if (j==8)
        return seg[i][j]+lazy[i]*2;
    return seg[i][j]-lazy[i]*2;
}

void passDown(int i)
{
    lazy[i*2+1]+=lazy[i];
    lazy[i*2+2]+=lazy[i];
    lazy[i]=0;
}

void recalc(int i)
{
    int l=(i<<1)+1,r=(i<<1)+2;
    seg[i][0]=max({f(l,0)+f(r,0),f(l,1)+f(r,4),f(l,2)+f(r,3)});
    seg[i][1]=max({f(l,1),f(r,1),f(l,0)+f(r,1),f(l,1)+f(r,7),f(l,2)+f(r,5)});
    seg[i][2]=max({f(l,2),f(r,2),f(l,0)+f(r,2),f(l,1)+f(r,8),f(l,2)+f(r,6)});
    seg[i][3]=max({f(l,3),f(r,3),f(l,3)+f(r,0),f(l,5)+f(r,4),f(l,6)+f(r,3)});
    seg[i][4]=max({f(l,4),f(r,4),f(l,4)+f(r,0),f(l,7)+f(r,4),f(l,8)+f(r,3)});
    seg[i][5]=max({f(l,5),f(r,5),f(l,3)+f(r,1),f(l,5)+f(r,7),f(l,6)+f(r,5)});
    seg[i][6]=max({f(l,6),f(r,6),f(l,3)+f(r,2),f(l,5)+f(r,8),f(l,6)+f(r,6)});
    seg[i][7]=max({f(l,7),f(r,7),f(l,4)+f(r,1),f(l,7)+f(r,7),f(l,8)+f(r,5)});
    seg[i][8]=max({f(l,8),f(r,8),f(l,4)+f(r,2),f(l,7)+f(r,8),f(l,8)+f(r,6)});
}

/**
0: |
1: |-  -1
2: |+  1
3: -|  -1
4: +|  1
5: -|- -2
6: -|+ 0
7: +|- 0
8: +|+ 2
**/

void build(int i, int l, int r)
{
    if (l==r)
    {
        cin>>seg[i][2];
        seg[i][1]=seg[i][3]=-seg[i][2];
        seg[i][4]=seg[i][2];
        for (int j=5;j<9;++j)
            seg[i][j]=INF;
        return;
    }
    build((i<<1)+1,l,(l+r)>>1);
    build((i<<1)+2,((l+r)>>1)+1,r);
    recalc(i);
}

void update(int i, int cL, int cR, int l, int r, int x)
{
    if (r<cL||cR<l)
        return;
    if (l<=cL&&cR<=r)
    {
        lazy[i]+=x;
        return;
    }
    passDown(i);
    update((i<<1)+1,cL,(cL+cR)>>1,l,r,x);
    update((i<<1)+2,((cL+cR)>>1)+1,cR,l,r,x);
    recalc(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,l,r,x;
    cin>>n>>q;
    build(0,1,n);
    while (q--)
    {
        cin>>l>>r>>x;
        update(0,1,n,l,r,x);
        cout<<seg[0][0]<<"\n";
    }
    return 0;
}