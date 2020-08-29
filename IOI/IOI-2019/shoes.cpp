#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int segTree[1000000];

void update(int i, int cL, int cR, int r)
{
    if (cR<=r)
    {
        ++segTree[i];
        return;
    }
    if (r<cL)
        return;
    int m=cL+((cR-cL)>>1);
    update((i<<1)+1,cL,m,r);
    update((i<<1)+2,m+1,cR,r);
}

int query(int i, int cL, int cR, int x)
{
    if (x<cL||cR<x)
        return 0;
    if (cL==cR)
        return segTree[i];
    int m=cL+((cR-cL)>>1);
    return segTree[i]+query((i<<1)+1,cL,m,x)+query((i<<1)+2,m+1,cR,x);
}

vector<int> neg[100001];
vector<int> pos[100001];

ll count_swaps(vector<int> a)
{
    int n=sz(a),c=-1;
    ll ans=0;
    for (int i=0;i<n;++i)
    {
        if (a[i]<0)
            neg[-a[i]].push_back(i);
        else
            pos[a[i]].push_back(i);
    }
    n>>=1;
    pair<int,int> p[n];
    for (int i=1;i<100001;++i)
        for (int j=0;j<sz(pos[i]);++j)
            p[++c]={min(neg[i][j],pos[i][j]),max(neg[i][j],pos[i][j])};
    sort(p,p+n);
    for (int i=0;i<n;++i)
    {
        if (a[p[i].first]<0)
        {
            ans+=query(0,0,200000,p[i].first)+p[i].first-(i<<1);
            update(0,0,200000,p[i].first);
            ans+=query(0,0,200000,p[i].second)+p[i].second-(i<<1)-1;
            update(0,0,200000,p[i].second);
        }
        else
        {
            ans+=query(0,0,200000,p[i].second)+p[i].second-(i<<1);
            update(0,0,200000,p[i].second);
            ans+=query(0,0,200000,p[i].first)+p[i].first-(i<<1)-1;
            update(0,0,200000,p[i].first);
        }
    }
    return ans;
}