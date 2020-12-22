#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn=1e5+1;
vector<int> pos[maxn];
int n,x,l,r,m;

bool inRange(int k, int L, int R)
{
    if (pos[k].empty())
        return 0;
    l=0;r=sz(pos[k])-1;
    while (l<r)
    {
        m=l+((r-l)>>1);
        //cout<<l<<" "<<r<<" "<<m<<"\n";
        if (pos[k][m]<L)
            l=m+1;
        else
            r=m;
    }
    if (L<=pos[k][l]&&pos[k][l]<=R)
        return 1;
    return 0;
}

bool hasAll(int L, int R, int k)
{
    if (R<L)
        return 0;
    if (R-L+1<k)
        return 0;
    for (int i=1;i<=k;++i)
        if (!inRange(i,L,R))
            return 0;
    return 1;
}

bool isntPresent(int k)
{
    x=pos[k].size();
    if (x==0)
    {
        if (hasAll(0,n-1,k-1))
            return 0;
        return 1;
    }
    for (int i=1;i<x;++i)
        if (hasAll(pos[k][i-1],pos[k][i],k-1))
            return 0;
    if (hasAll(0,pos[k][0],k-1))
        return 0;
    if (hasAll(pos[k][x-1],n-1,k-1))
        return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        pos[k].push_back(i);
    }
    if (sz(pos[1])==n)
    {
        cout<<1;
        return 0;
    }
    for (int i=2;i;++i)
    {
        if (isntPresent(i))
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}