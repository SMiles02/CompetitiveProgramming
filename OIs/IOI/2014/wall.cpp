#include <bits/stdc++.h>
using namespace std;

const int INF = 1e5, mn = 2e6+7;
int seg[mn<<2][2];

void passDown(int i)
{
    for (int j=i*2+1;j<i*2+3;++j)
    {
        seg[j][0]=max(seg[j][0],seg[i][0]);
        seg[j][1]=max(seg[j][0],seg[j][1]);
        seg[j][1]=min(seg[j][1],seg[i][1]);
        seg[j][0]=min(seg[j][0],seg[j][1]);
    }
    seg[i][0]=0;
    seg[i][1]=INF;
}

void update(int i, int l, int r, int op, int L, int R, int h)
{
    if (R<l||r<L)
        return;
    if (L<=l&&r<=R)
    {
        if (op==1)
        {
            seg[i][0]=max(seg[i][0],h);
            seg[i][1]=max(seg[i][1],h);
        }
        else
        {
            seg[i][0]=min(seg[i][0],h);
            seg[i][1]=min(seg[i][1],h);
        }
        return;
    }
    passDown(i);
    update(i*2+1,l,l+(r-l)/2,op,L,R,h);
    update(i*2+2,l+(r-l)/2+1,r,op,L,R,h);
}

void calc(int i, int l, int r, int ans[])
{
    if (l==r)
    {
        ans[l]=seg[i][0];
        return;
    }
    passDown(i);
    calc(i*2+1,l,l+(r-l)/2,ans);
    calc(i*2+2,l+(r-l)/2+1,r,ans);
}

void buildWall(int n, int k, int op[], int l[], int r[],
int h[], int ans[])
{
    for (int i=0;i<k;++i)
        update(0,0,n-1,op[i],l[i],r[i],h[i]);
    calc(0,0,n-1,ans);
}