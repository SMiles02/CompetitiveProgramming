#include <bits/stdc++.h>
using namespace std;

const int mn = 150003, INF = 1e9+7;
int segTree[mn<<2],ans[mn];

void build(int i, int l, int r)
{
    if (l==r)
    {
        segTree[i]=ans[l];
        return;
    }
    build((i<<1)+1,l,l+((r-l)>>1));
    build((i<<1)+2,l+((r-l)>>1)+1,r);
    segTree[i]=min(segTree[(i<<1)+1],segTree[(i<<1)+2]);
}

int query(int i, int cL, int cR, int l, int r)
{
    if (r<cL||cR<l)
        return INF;
    if (l<=cL&&cR<=r)
        return segTree[i];
    return min(query((i<<1)+1,cL,cL+((cR-cL)>>1),l,r),query((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r));
}

vector<int> v[mn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int w,x,y,z,k,p,q,final=INF;;
    cin>>w>>x>>y>>z;
    int b[x+1],c[y+1],d[z+1];
    for (int i=1;i<=w;++i)
        cin>>ans[i];
    for (int i=1;i<=x;++i)
        cin>>b[i];
    for (int i=1;i<=y;++i)
        cin>>c[i];
    for (int i=1;i<=z;++i)
        cin>>d[i];
    build(0,1,w);
    for (int i=1;i<=x;++i)
    {
        v[i].clear();
        v[i].push_back(0);
        v[i].push_back(w+1);
    }
    cin>>k;
    while (k--)
    {
        cin>>p>>q;
        v[q].push_back(p);
    }
    for (int i=1;i<=x;++i)
    {
        sort(v[i].begin(), v[i].end());
        ans[i]=INF;
        for (int j=v[i].size()-1;j>0;--j)
            if (v[i][j]-1>=v[i][j-1]+1)
                ans[i]=min(ans[i],query(0,1,w,v[i][j-1]+1,v[i][j]-1)+b[i]);
    }
    build(0,1,x);
    for (int i=1;i<=y;++i)
    {
        v[i].clear();
        v[i].push_back(0);
        v[i].push_back(x+1);
    }
    cin>>k;
    while (k--)
    {
        cin>>p>>q;
        v[q].push_back(p);
    }
    for (int i=1;i<=y;++i)
    {
        sort(v[i].begin(), v[i].end());
        ans[i]=INF;
        for (int j=v[i].size()-1;j>0;--j)
            if (v[i][j]-1>=v[i][j-1]+1)
                ans[i]=min(ans[i],query(0,1,x,v[i][j-1]+1,v[i][j]-1)+c[i]);
    }
    build(0,1,y);
    for (int i=1;i<=z;++i)
    {
        v[i].clear();
        v[i].push_back(0);
        v[i].push_back(y+1);
    }
    cin>>k;
    while (k--)
    {
        cin>>p>>q;
        v[q].push_back(p);
    }
    for (int i=1;i<=z;++i)
    {
        sort(v[i].begin(), v[i].end());
        ans[i]=INF;
        for (int j=v[i].size()-1;j>0;--j)
            if (v[i][j]-1>=v[i][j-1]+1)
                ans[i]=min(ans[i],query(0,1,y,v[i][j-1]+1,v[i][j]-1)+d[i]);
        final=min(final,ans[i]);
    }
    if (final==INF)
        final=-1;
    cout<<final;
    return 0;
}