#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int n,a,b,mx,sub[N],bit[N];
long long ans;
vector<int> e[N];
bitset<N> black;

void update(int i, int d)
{
    while (i<N)
    {
        bit[i]+=d;
        i+=i&-i;
    }
}

int query(int l, int r)
{
    int ret = 0;
    while (r)
    {
        ret+=bit[r];
        r-=r&-r;
    }
    while (l)
    {
        ret-=bit[l];
        l-=l&-l;
    }
    return ret;
}

int subDfs(int c, int p)
{
    sub[c]=1;
    for (int i : e[c])
        if (i!=p&&!black[i])
            sub[c]+=subDfs(i,c);
    return sub[c];
}

int findCentroid(int c, int p, int t)
{
    for (int i : e[c])
        if (!black[i]&&i!=p&&sub[i]>t)
            return findCentroid(i,c,t);
    return c;
}

void dfs(int c, int p, int h, bool fill)
{
    if (h>b)
        return;
    mx=max(mx,h);
    if (fill)
        update(h,1);
    else
        ans+=query(max(a-h-1,0),b-h);
    for (int i : e[c])
        if (i!=p&&!black[i])
            dfs(i,c,h+1,fill);
}

void solve(int x)
{
    int c = findCentroid(x,0,subDfs(x,0)/2);
    mx=0;
    black[c]=1;
    for (int i : e[c])
        if (!black[i])
        {
            dfs(i,c,1,0);
            dfs(i,c,1,1);
        }
    ans+=query(a-1,b);
    for (int i=1;i<=mx;++i)
        update(i,-bit[i]);
    for (int i : e[c])
        if (!black[i])
            solve(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y;
    cin>>n>>a>>b;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    solve(1);
    cout<<ans;
    return 0;
}