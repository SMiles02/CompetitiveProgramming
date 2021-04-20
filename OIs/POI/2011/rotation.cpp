#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+7;
int bit[N],tin[N*2],tout[N*2],a[N],e[N*2][2],t,u;
ll ans;

int dfs()
{
    int x=u++,y;
    cin>>y;
    if (y==0)
    {
        e[x][0]=dfs();
        tin[x]=tin[e[x][0]];
        e[x][1]=dfs();
    }
    else
    {
        a[t]=y;
        tin[x]=t++;
    }
    tout[x]=t;
    return x;
}

void update(int i, int d)
{
    while (i<N)
    {
        bit[i]+=d;
        i+=i&-i;
    }
}

int query(int i)
{
    int r=0;
    while (i)
    {
        r+=bit[i];
        i-=i&-i;
    }
    return r;
}

void dfs(int c, bool keep)
{
    if (e[c][0]==0)
    {
        if (keep==0)
            return;
        update(a[tin[c]],1);
        return;
    }
    int x=0,y=0;
    ll z=0;
    if (tout[e[c][0]]-tin[e[c][0]]<tout[e[c][1]]-tin[e[c][1]])
        x=1;
    else
        y=1;
    dfs(e[c][y],0);
    dfs(e[c][x],1);
    for (int i=tin[e[c][y]];i<tout[e[c][y]];++i)
        z+=query(a[i]);
    ans+=min(z,1LL*(tout[e[c][0]]-tin[e[c][0]])*(tout[e[c][1]]-tin[e[c][1]])-z);
    if (keep==0)
        for (int i=tin[e[c][x]];i<tout[e[c][x]];++i)
            update(a[i],-1);
    else
        for (int i=tin[e[c][y]];i<tout[e[c][y]];++i)
            update(a[i],1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    dfs();
    dfs(0,1);
    cout<<ans;
    return 0;
}