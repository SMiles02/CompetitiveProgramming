#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;
 
const int MAXN=1e5+10;
int n,m,o;
vector<pii> edges[MAXN];
int scores[MAXN], cur[MAXN], ans[5*MAXN], counter[MAXN];
bool done[MAXN];
 
void dfsTree(int c, int p, int x)
{
    for (pii i : edges[c])
        if (i.f!=p)
        {
            dfsTree(i.f,c,i.s);
            cur[c]+=ans[i.s];
        }
    if (c!=1)
    {
        ans[x]=scores[c]-cur[c];
        cur[c]+=ans[x];
    }
}
 
void treeCase()
{
    dfsTree(1,0,0);
    if (scores[1]!=cur[1])
    {
        cout<<0;
        return;
    }
    for (int i=0;i<m;++i)
        cout<<ans[i]*2<<"\n";
} 
 
vector<int> circle,vals;
 
void dfs(int c, int p)
{
    circle.push_back(c);
    done[c]=1;
    for (pii i : edges[c])
        if (i.f!=p)
        {
            if (i.f==o)
            {
                vals.push_back(i.s);
                return;
            }
            if (!done[i.f])
            {
                vals.push_back(i.s);
                dfs(i.f,c);
            }
        }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int u,v,x=0;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>scores[i];
    for (int i=0;i<m;++i)
    {
        cin>>u>>v;
        edges[u].push_back({v,i});
        edges[v].push_back({u,i});
    }
    if (m==n-1)
    {
        treeCase();
        return 0;
    }
    if (m>n)
    {
        cout<<0;
        return 0;
    }
    stack<int> st;
    for (int i=1;i<=n;++i)
    {
        counter[i]=sz(edges[i]);
        if (counter[i]==1)
            st.push(i);
    }
    while (sz(st))
    {
        ++x;
        v=st.top();st.pop();
        done[v]=1;
        for (pii i : edges[v])
            if (!done[i.f])
            {
                u=i.s;
                ans[u]=scores[v]-cur[v];
                cur[v]+=ans[u];
                cur[i.f]+=ans[u];
                --counter[i.f];
                if (counter[i.f]==1)
                    st.push(i.f);
            }
    }
    if ((n-x+1)&1)
    {
        cout<<0;
        return 0;
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            o=i;
            dfs(o,0);
            break;
        }
    ll tot=0;
    for (int i=0;i<n-x;++i)
    {
        if (i&1)
            tot-=(scores[circle[i]]-cur[circle[i]]);
        else
            tot+=(scores[circle[i]]-cur[circle[i]]);
    }
    if (tot&1)
    {
        cout<<0;
        return 0;
    }
    ans[vals.back()]=(tot>>1);
    ans[vals[0]]=scores[circle[0]]-cur[circle[0]]-ans[vals.back()];
    for (int i=1;i+1<n-x;++i)
        ans[vals[i]]=scores[circle[i]]-cur[circle[i]]-ans[vals[i-1]];
    for (int i=0;i<m;++i)
        cout<<ans[i]*2<<"\n";
    return 0;
}