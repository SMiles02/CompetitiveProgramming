#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,int> heights;
map<int,vector<int>> edges;
map<int,int> parent;
map<int,int> done;

void dfs(int cur, int h, int p)
{
    done[cur]=1;
    parent[cur]=p;
    heights[cur]=h;
    int k=sz(edges[cur]);
    for (int i=0;i<k;++i)
    {
        if (!done[edges[cur][i]])
        {
            dfs(edges[cur][i],h+1,cur);
        }
    }
}

int LCA(int a, int b)
{
    while (heights[a]>heights[b])
    {
        a=parent[a];
    }
    while (heights[a]<heights[b])
    {
        b=parent[b];
    }
    while (a!=b)
    {
        a=parent[a];
        b=parent[b];
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,u,v,maxi=0,x,jfk,cur=1;
    cin>>n;
    vector<pair<int,int>> w;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0,-1);
    for (int i=1;i<=n;++i)
    {
        for (int j=i+1;j<=n;++j)
        {
            x=LCA(i,j);
            if (heights[i]+heights[j]-2*(heights[x])>maxi)
            {
                maxi=heights[i]+heights[j]-2*(heights[x]);
                w.clear();
                w.push_back({i,j});
            }
            else if (heights[i]+heights[j]-2*(heights[x])==maxi)
            {
                w.push_back({i,j});
            }
        }
    }
    jfk=n/2;
    --jfk;
    random_shuffle(w.begin(), w.end());
    cout<<"? "<<w[0].first<<" "<<w[0].second<<endl;
    cin>>x;
    while (jfk>1)
    {
        cout<<"? "<<w[cur].first<<" "<<w[cur].second<<endl;
        cin>>u;
        cout<<"? "<<x<<" "<<u<<endl;
        cin>>x;
        ++cur;
        jfk-=2;
    }
    cout<<"! "<<x;
    //.
    return 0;
}