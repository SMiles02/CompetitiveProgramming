//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+3;
int n, seg[N*4][2], a[N];

void turnOn(int i, int l, int r, int j)
{
    if (l==r)
    {
        seg[i][0]=seg[i][1]=a[l]=1;
        return;
    }
    if (j<=l+(r-l)/2)
        turnOn(i*2+1,l,l+(r-l)/2,j);
    else
        turnOn(i*2+2,l+(r-l)/2+1,r,j);
    seg[i][0]=seg[i*2+1][0]+seg[i*2+2][0];
    seg[i][1]=seg[i*2+1][1]&seg[i*2+2][1];
}

int sm(int i, int l, int r, int qL, int qR)
{
    if (qR<l||r<qL)
        return 0;
    if (qL<=l&&r<=qR)
        return seg[i][0];
    return sm(i*2+1,l,l+(r-l)/2,qL,qR) + sm(i*2+2,l+(r-l)/2+1,r,qL,qR);
}

bool findLast(int i, int l, int r, int qL, int qR)
{
    if (qR<l||r<qL||seg[i][1])
        return 0;
    if (l==r)
    {
        turnOn(0,1,n,l);
        return 1;
    }
    bool x=findLast(i*2+2,l+(r-l)/2+1,r,qL,qR);
    if (x==0)
        return findLast(i*2+1,l,l+(r-l)/2,qL,qR);
    return 1;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<array<int,3>> v(m);
    for (int i=0;i<m;++i)
        cin>>v[i][1]>>v[i][0]>>v[i][2];
    sort(v.begin(), v.end());
    for (auto i : v)
        while (sm(0,1,n,i[1],i[0])<i[2])
            findLast(0,1,n,i[1],i[0]);
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    return 0;
}