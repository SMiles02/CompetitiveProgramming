#include <bits/stdc++.h>
using namespace std;
 
const int MAXN=2e5+1;
int d[MAXN][3],x,y=-1;
vector<int> edges[MAXN];
 
void dfs(int c, int p, int h, int k)
{
    d[c][k]=h;
    if (h>y)
    {
        y=h;
        x=c;
    }
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c,h+1,k);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,u,v;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0,0,0);
    y=-1;
    dfs(x,0,0,1);
    y=-1;
    dfs(x,0,0,2);
    for (int i=1;i<=n;++i)
        cout<<max(d[i][1],d[i][2])<<" ";
    return 0;
}