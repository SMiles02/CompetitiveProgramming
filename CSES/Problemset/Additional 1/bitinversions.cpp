#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1, INF = -1e9;
int seg[N*4][4];
string s;

void calc(int i, int l, int r)
{
    int x=i*2+1,y=i*2+2;
    if (s[l+(r-l)/2]==s[l+(r-l)/2+1])
    {
        if (seg[x][3]>0)
            seg[i][1]=seg[x][3]+seg[y][1];
        else
            seg[i][1]=seg[x][1];
        if (seg[y][3]>0)
            seg[i][2]=seg[x][2]+seg[y][3];
        else
            seg[i][2]=seg[y][2];
        if (seg[x][3]+seg[y][3]>0)
            seg[i][3]=r-l+1;
        else
            seg[i][3]=INF;
        seg[i][0]=max({seg[x][0],seg[y][0],seg[i][1],seg[i][2],seg[i][3],seg[x][2]+seg[y][1]});
    }
    else
    {
        seg[i][0]=max(seg[x][0],seg[y][0]);
        seg[i][1]=seg[x][1];
        seg[i][2]=seg[y][2];
        seg[i][3]=INF;
    }
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        for (int j=0;j<4;++j)
            seg[i][j]=1;
        return;
    }
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
    calc(i,l,r);
}

void update(int i, int l, int r, int x)
{
    if (x<l||r<x)
        return;
    if (l==r)
    {
        if (s[l]=='0')
            s[l]='1';
        else
            s[l]='0';
        return;
    }
    update(i*2+1,l,l+(r-l)/2,x);
    update(i*2+2,l+(r-l)/2+1,r,x);
    calc(i,l,r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x;
    cin>>s;
    n=-1+s.size();
    build(0,0,n);
    cin>>q;
    while (q--)
    {
        cin>>x;
        update(0,0,n,x-1);
        cout<<seg[0][0]<<" ";
    }
    return 0;
}