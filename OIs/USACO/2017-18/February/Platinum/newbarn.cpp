#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7, lg = 17;
int t,tin[N],tout[N],up[lg][N],ans[N][4],h[N],p[N],sub[N],ct,o;
vector<int> e[N];
bitset<N> b;

void dfs(int c, int d)
{
    tin[c]=++t;
    up[0][c]=d;
    for (int i=1;i<lg;++i)
        up[i][c]=up[i-1][up[i-1][c]];
    for (int i : e[c])
        if (i!=d)
        {
            h[i]=h[c]+1;
            dfs(i,c);
        }
    tout[c]=++t;
}

bool isAncestor(int x, int y)
{
    if (tin[x]<=tin[y]&&tout[y]<=tout[x])
        return 1;
    return 0;
}

int lca(int x, int y)
{
    if (isAncestor(x,y))
        return x;
    if (isAncestor(y,x))
        return y;
    for (int i=lg-1;i>=0;--i)
        if (!isAncestor(up[i][x],y))
            x=up[i][x];
    return up[0][x];
}

int dist(int x, int y)
{
    return h[x]+h[y]-h[lca(x,y)]*2;
}

void subDfs(int c, int d)
{
    sub[c]=1;
    for (int i : e[c])
        if (i!=d&&!b[i])
        {
            subDfs(i,c);
            sub[c]+=sub[i];
        }
}

void centDfs(int c, int d, int r)
{
    int mx=r-sub[c];
    for (int i : e[c])
        if (i!=d&&!b[i])
        {
            centDfs(i,c,r);
            mx=max(mx,sub[i]);
        }
    if (mx<=r/2)
        ct=c;
}

void build(int r, int l)
{
    subDfs(r,0);
    centDfs(r,0,sub[r]);
    int C = ct;
    b[C]=1;
    p[C]=l;
    for (int i : e[C])
        if (!b[i])
            build(i,C);
}

void turnOn(int c)
{
    o=N-1;
    p[N-1]=c;
    for (int i=c;i;i=p[i],o=p[o])
    {
        t=dist(i,c);
        if (o==ans[i][2])
            ans[i][0]=max(ans[i][0],t);
        else if (o==ans[i][3])
            ans[i][1]=max(ans[i][1],t);
        else if (t>=ans[i][0])
        {
            swap(ans[i][0],ans[i][1]);
            swap(ans[i][2],ans[i][3]);
            ans[i][0]=t;
            ans[i][2]=o;
        }
        else if (t>=ans[i][1])
        {
            ans[i][1]=t;
            ans[i][3]=o;
        }
        if (ans[i][0]<ans[i][1])
        {
            swap(ans[i][0],ans[i][1]);
            swap(ans[i][2],ans[i][3]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("newbarn.in", "r", stdin);
    freopen("newbarn.out", "w", stdout);
    int n,k=0;
    cin>>n;
    vector<char> v(n);
    vector<int> w(n);
    for (int i=0;i<n;++i)
    {
        cin>>v[i]>>w[i];
        if (v[i]=='B')
        {
            ++k;
            if (w[i]!=-1)
            {
                e[w[i]].push_back(k);
                e[k].push_back(w[i]);
            }
            w[i]=k;
        }
    }
    tout[0]=1e9;
    for (int i=1;i<=k;++i)
        if (!b[i])
        {
            dfs(i,0);
            build(i,0);
        }
    for (int i=0;i<n;++i)
    {
        if (v[i]=='Q')
        {
            k=0;
            o=N-2;
            p[N-2]=w[i];
            for (int j=w[i];j;j=p[j],o=p[o])
            {
                t=dist(j,w[i]);
                if (o!=ans[j][3]&&ans[j][3]!=0)
                    k=max(k,ans[j][1]+t);
                if (o!=ans[j][2]&&ans[j][2]!=0)
                    k=max(k,ans[j][0]+t);
            }
            cout<<k<<"\n";
        }
        else
            turnOn(w[i]);
    }
    return 0;
}