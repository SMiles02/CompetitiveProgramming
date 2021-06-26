#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7, M = 3e5+7, L = 19;
int n, k, t, a[N], b[N], d[N], p[N], dsu[N*2], eN[M], up[L][N*2], range[N*2][2], s[N*8];
vector<int> e[N*2];
array<int,2> eL[M], qL[N+M];
bitset<M> off;
bitset<N*2> done, black;

int parent(int x)
{
    if (dsu[x]==x)
        return x;
    return dsu[x] = parent(dsu[x]);
}

void dfs(int c)
{
    for (int i=1;i<L;++i)
        up[i][c]=up[i-1][up[i-1][c]];
    range[c][0]=t+1;
    done[c]=1;
    if (e[c].empty())
    {
        range[c][1]=++t;
        b[t]=a[c];
        d[c]=t;
        return;
    }
    for (int i : e[c])
        dfs(i);
    range[c][1]=t;
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        s[i]=b[l];
        return;
    }
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
    s[i]=max(s[i*2+1],s[i*2+2]);
}

int query(int i, int l, int r, int qL, int qR)
{
    if (qR<l||r<qL)
        return 0;
    if (qL<=l&&r<=qR)
        return s[i];
    return max(query(i*2+1,l,l+(r-l)/2,qL,qR),query(i*2+2,l+(r-l)/2+1,r,qL,qR));
}

void update(int i, int l, int r, int x)
{
    if (x<l||r<x)
        return;
    if (l==r)
    {
        s[i]=0;
        return;
    }
    update(i*2+1,l,l+(r-l)/2,x);
    update(i*2+2,l+(r-l)/2+1,r,x);
    s[i]=max(s[i*2+1],s[i*2+2]);
}

void walk(int i, int l, int r)
{
    if (l==r)
    {
        cout<<l<<": "<<s[i]<<"\n";
        return;
    }
    walk(i*2+1,l,l+(r-l)/2);
    walk(i*2+2,l+(r-l)/2+1,r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,q,x,y;
    cin>>n>>m>>q;
    k=n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        p[a[i]]=i;
    }
    for (int i=1;i<=m;++i)
        cin>>eL[i][0]>>eL[i][1];
    for (int i=0;i<q;++i)
    {
        cin>>qL[i][0]>>qL[i][1];
        if (qL[i][0]==2)
            off[qL[i][1]]=1;
    }
    for (int i=1;i<=n;++i)
        dsu[i]=i;
    for (int i=1;i<=m;++i)
        if (!off[i]&&parent(dsu[eL[i][0]])!=parent(dsu[eL[i][1]]))
        {
            ++k;
            x=parent(dsu[eL[i][0]]);
            y=parent(dsu[eL[i][1]]);
            dsu[x]=dsu[y]=dsu[k]=k;
            up[0][x]=k;
            up[0][y]=k;
            e[k].push_back(x);
            e[k].push_back(y);
        }
    for (int i=q-1;i>=0;--i)
        if (qL[i][0]==2&&parent(dsu[eL[qL[i][1]][0]])!=parent(dsu[eL[qL[i][1]][1]]))
        {
            eN[qL[i][1]]=++k;
            x=parent(dsu[eL[qL[i][1]][0]]);
            y=parent(dsu[eL[qL[i][1]][1]]);
            dsu[x]=dsu[y]=dsu[k]=k;
            up[0][x]=k;
            up[0][y]=k;
            e[k].push_back(x);
            e[k].push_back(y);
        }
    for (int i=k;i>0;--i)
        if (!done[i])
            dfs(i);
    build(0,1,t);
    black[0]=1;
    for (int i=0;i<q;++i)
    {
        if (qL[i][0]==2)
            black[eN[qL[i][1]]]=1;
        else
        {
            x=qL[i][1];
            for (int j=L-1;j>=0;--j)
                if (!black[up[j][x]])
                    x=up[j][x];
            y=query(0,1,t,range[x][0],range[x][1]);
            cout<<y<<"\n";
            update(0,1,t,d[p[y]]);
        }
    }
    return 0;
}