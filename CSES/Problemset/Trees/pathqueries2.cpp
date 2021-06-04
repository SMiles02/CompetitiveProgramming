#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+3;
int n, seg[N<<2], p[N], heavy[N], pos[N], v[N], head[N], height[N], ct;
vector<int> e[N];
 
void update(int i, int l, int r, int x, int y)
{
    if (x<l||r<x)
        return;
    if (l==r)
    {
        seg[i]=y;
        return;
    }
    if (x<=l+(r-l)/2)
        update(i*2+1,l,l+(r-l)/2,x,y);
    else
        update(i*2+2,l+(r-l)/2+1,r,x,y);
    seg[i]=max(seg[i*2+1],seg[i*2+2]);
}
 
int query(int i, int l, int r, int x, int y)
{
    if (x<=l&&r<=y)
        return seg[i];
    int ret=0;
    if (x<=l+(r-l)/2)
        ret=max(ret,query(i*2+1,l,l+(r-l)/2,x,y));
    if (l+(r-l)/2<y)
        ret=max(ret,query(i*2+2,l+(r-l)/2+1,r,x,y));
    return ret;
}
 
int dfs(int c)
{
    int sz=1, mx=0, tmp;
    for (int i : e[c])
        if (i!=p[c])
        {
            p[i]=c;
            height[i]=height[c]+1;
            tmp=dfs(i);
            sz+=tmp;
            if (tmp>mx)
            {
                heavy[c]=i;
                mx=tmp;
            }
        }
    return sz;
}
 
void decompose(int c, int h)
{
    head[c]=h;
    pos[c]=++ct;
    update(0,1,n,ct,v[c]);
    if (heavy[c])
        decompose(heavy[c],h);
    for (int i : e[c])
        if (i!=p[c]&&i!=heavy[c])
            decompose(i,i);
}

int query(int x, int y)
{
    int ans=0;
    while (head[x]!=head[y])
    {
        if (height[head[x]]<height[head[y]])
            swap(x,y);
        ans=max(ans,query(0,1,n,pos[head[x]],pos[x]));
        x=p[head[x]];
    }
    if (height[x]<height[y])
        swap(x,y);
    return max(ans,query(0,1,n,pos[y],pos[x]));
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,w,x,y;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
        cin>>v[i];
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1);
    decompose(1,1);
    while (q--)
    {
        cin>>w>>x>>y;
        if (w==1)
            update(0,1,n,pos[x],y);
        else
            cout<<query(x,y)<<" ";
    }
    return 0;
}