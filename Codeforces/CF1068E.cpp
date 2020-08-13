#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> edges[100001];
int distFromLeaf[100001];
bool ok=1;

void dfs1(int c, int p)
{
    distFromLeaf[c]=distFromLeaf[p]+1;
    if (sz(edges[c])==1)
        distFromLeaf[c]=0;
    for (int i : edges[c])
        if (i!=p)
        {
            dfs1(i,c);
            distFromLeaf[c]=min(distFromLeaf[c],distFromLeaf[i]+1);
        }
}

void dfs(int c, int p)
{
    int x=0;
    for (int i : edges[c])
        if (i!=p)
        {
            ++x;
            if (distFromLeaf[i]+1!=distFromLeaf[c])
            {
                ok=0;
                //cout<<i<<" "<<c<<"\n";
            }
            dfs(i,c);
        }
    if (x==1||x==2)
        ok=0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,u,v;
    cin>>n>>k;
    distFromLeaf[0]=1e9;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs1(1,0);
    u=-1;v=0;
    for (int i=1;i<=n;++i)
    {
        if (distFromLeaf[i]>=n)
        {
            cout<<"No";
            return 0;
        }
        if (distFromLeaf[i]>u)
        {
            u=distFromLeaf[i];
            v=i;
        }
    }
    dfs(v,0);
    if (u!=k)
    {
        //cout<<"inhere\n";
        ok=0;
    }
    if (ok)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}