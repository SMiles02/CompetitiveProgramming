#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
bool done[100001];
vector<int> edges[100001];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,v;
    cin>>n>>m;
    while (m--)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int dist[n+1];
    done[n]=1;
    dist[n]=1;
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        v=q.front();
        q.pop();
        for (int x : edges[v])
            if (!done[x])
            {
                done[x]=1;
                dist[x]=dist[v]+1;
                q.push(x);
            }
    }
    if (!done[1])
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    v=1;
    cout<<dist[1]<<"\n";
    while (1)
    {
        cout<<v<<" ";
        if (v==n)
            return 0;
        for (auto x : edges[v])
            if (dist[x]<dist[v])
            {
                v=x;
                break;
            }
    }
    return 0;
}