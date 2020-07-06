#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool done1[200001];
bool done2[200001];
map<int,vector<int>> edges;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,u,vv,ans=0;
    cin>>n>>m>>k;
    int a[k];
    for (int i=0;i<k;++i)
        cin>>a[i];
    while (m--)
    {
        cin>>u>>vv;
        edges[u].push_back(vv);
        edges[vv].push_back(u);
    }
    int x[n+1];
    int y[n+1];
    x[1]=0;
    y[n]=0;
    done1[1]=1;
    done2[n]=1;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        u=q.front();
        q.pop();
        for (auto i : edges[u])
        {
            if (!done1[i])
            {
                done1[i]=1;
                x[i]=x[u]+1;
                q.push(i);
            }
        }
    }
    q.push(n);
    while (!q.empty())
    {
        u=q.front();
        q.pop();
        for (auto i : edges[u])
        {
            if (!done2[i])
            {
                done2[i]=1;
                y[i]=y[u]+1;
                q.push(i);
            }
        }
    }
    vector<pair<int,pair<int,int>>> v;
    for (int i=0;i<k;++i)
    {
        v.push_back({x[a[i]]-y[a[i]],{x[a[i]],y[a[i]]}});
    }
    sort(v.begin(), v.end());
    u=v[0].second.first;
    for (int i=1;i<k;++i)
    {
        ans=max(ans,u+v[i].second.second);
        u=max(u,v[i].second.first);
    }
    cout<<min(ans+1,x[n]);
    return 0;
}