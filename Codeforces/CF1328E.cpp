#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
map<int,vector<int>> edges;
int parent[200001];
int height[200001];
int done[200001]={0};
int tin[200001];
int tout[200001];
int T=0;
 
void dfs(int cur, int h, int p)
{
    parent[cur]=p;
    height[cur]=h;
    done[cur]=1;
    tin[cur]=T++;
    int k=sz(edges[cur]);
    for (int i=0;i<k;++i)
    {
        if (!done[edges[cur][i]])
        {
            dfs(edges[cur][i],h+1,cur);
        }
    }
    tout[cur]=T++;
    return;
}
 
void solve()
{
    int maxH=0,cur=1,k,x;
    cin>>k;
    vector<int> v;
    for (int i=0;i<k;++i)
    {
        cin>>x;
        v.push_back(max(parent[x],1));
        if (height[x]>maxH)
        {
            cur=x;
            maxH=height[x];
        }
    }
    for (int i=0;i<k;++i)
    {
        if (!(tin[v[i]]<=tin[cur]&&tout[cur]<=tout[v[i]]))
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,a,b;
    cin>>n>>q;
    for (int i=1;i<n;++i)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1,0,0);
    parent[0]=-1;
    while (q--)
    {
        solve();
    }
    return 0;
}