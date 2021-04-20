#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+2;
int n,seg[N<<2][9];

void calc(int i)
{
    if (seg[i*2+2][0]==seg[i*2+2][4])
    {
        seg[i][3]=seg[i*2+2][3]+seg[i*2+1][3];
        seg[i][5]=seg[i*2+1][5];
    }
    else
    {
        seg[i][3]=seg[i*2+2][3];
        seg[i][5]=seg[i*2+2][5];
    }
    if (seg[i*2+1][0]==seg[i*2+1][4])
        seg[i][2]=seg[i*2+1][2]+seg[i*2+2][2];
    else
        seg[i][2]=seg[i*2+1][2];
    seg[i][1]=seg[i*2+1][3]+seg[i*2+2][2];
    seg[i][0]=max({seg[i][1],seg[i*2+1][0],seg[i*2+2][0]});
}

void passDown(int i)
{
    if (seg[i][6])
    {
        seg[i*2+1][6]=seg[i*2+2][6]=1;
        seg[i*2+1][7]=seg[i*2+2][7]=0;
    }
    else if (seg[i][7])
    {
        seg[i*2+1][6]=seg[i*2+2][6]=0;
        seg[i*2+1][7]=seg[i*2+2][7]=1;
    }
    seg[i][6]=seg[i][7]=0;
}

void recalc(int i)
{
    if (seg[i][6])
    {
        for (int j=0;j<4;++j)
            seg[i][j]=seg[i][4];
        seg[i][5]=seg[i][8];
    }
    else if (seg[i][7])
    {
        for (int j=0;j<4;++j)
            seg[i][j]=0;
        seg[i][5]=seg[i][8];
    }
    return;
}

void build(int i, int l, int r)
{
    seg[i][4]=r-l+1;
    seg[i][8]=l;
    if (l==r)
    {
        for (int j=0;j<4;++j)
            seg[i][j]=1;
        seg[i][5]=l;
        seg[i][6]=1;
        return;
    }
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
    calc(i);
}

void update(int i, int cL, int cR, int l, int r, int x)
{
    recalc(i);
    if (r<cL||cR<l)
        return;
    if (l<=cL&&cR<=r)
    {
        if (x==0)
        {
            //cout<<"fixing "<<cL<<" "<<cR<<"\n";
            seg[i][6]=1;
            seg[i][7]=0;
        }
        else
        {
            seg[i][6]=0;
            seg[i][7]=1;
        }
        for (int j=0;j<4;++j)
            seg[i][j]=(cR-cL+1)*(1-x);
        seg[i][5]=cL;
        return;
    }
    passDown(i);
    update(i*2+1,cL,cL+(cR-cL)/2,l,r,x);
    update(i*2+2,cL+(cR-cL)/2+1,cR,l,r,x);
    calc(i);
    // if (x==0)
    // {
    //     cout<<cL<<" "<<cR<<"\n";
    //     for (int j=0;j<6;++j)
    //         cout<<seg[i][j]<<" ";
    //     cout<<"\n";
    // }
}

void find(int i, int l, int r, int x)
{
    recalc(i);
    if (l==r)
    {
        update(0,1,n,l,l,1);
        return;
    }
    passDown(i);
    if (seg[i*2+1][0]>=x)
        find(i*2+1,l,l+(r-l)/2,x);
    else if (seg[i][1]>=x)
        update(0,1,n,seg[i][5],seg[i][5]+x-1,1);
    else
        find(i*2+2,l+(r-l)/2+1,r,x);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("seating.in", "r", stdin);
    freopen("seating.out", "w", stdout);
    int m,x,y,ans=0;
    char c;
    cin>>n>>m;
    build(0,1,n);
    while (m--)
    {
        //cout<<seg[0][0]<<"\n";
        cin>>c;
        if (c=='L')
        {
            cin>>x>>y;
            update(0,1,n,x,y,0);
        }
        else
        {
            cin>>x;
            if (seg[0][0]<x)
                ++ans;
            else
                find(0,1,n,x);
        }
    }
    cout<<ans;
	return 0;
}