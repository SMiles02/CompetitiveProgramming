#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool done[101];
map<int,vector<int>> edges;
map<int,vector<int>> groupMembers;
int group=0;

void dfs(int cur)
{
    groupMembers[group].push_back(cur);
    done[cur]=1;
    int k=sz(edges[cur]);
    for (int i=0;i<k;++i)
        if (!done[edges[cur][i]])
            dfs(edges[cur][i]);
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("conexidad.in", "r", stdin);
    freopen("conexidad.out", "w", stdout);
    int n,m,u,v,ans=0;
    cin>>n>>m;
    vector<pair<int,int>> components;
    while (m--)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            ++group;
            dfs(i);
            components.push_back({sz(groupMembers[group]),group});
        }
    set<pair<int,int>> verticesDone;
    set<pair<int,int>>::iterator it;
    sort(components.begin(), components.end());
    for (auto i : groupMembers[components.back().second])
        verticesDone.insert({0,i});
    components.pop_back();
    vector<pair<int,int>> toAdd;
    while (sz(components))
    {
        it=verticesDone.begin();
        u=(*it).first;v=(*it).second;
        verticesDone.erase(it);
        ans=max(ans,u+1);
        verticesDone.insert({u+1,v});
        toAdd.push_back({v,groupMembers[components.back().second].back()});
        verticesDone.insert({1,groupMembers[components.back().second].back()});
        groupMembers[components.back().second].pop_back();
        for (auto i : groupMembers[components.back().second])
            verticesDone.insert({0,i});
        components.pop_back(); 
    }
    cout<<ans<<"\n"<<sz(toAdd)<<"\n";
    for (auto i : toAdd)
        cout<<i.first<<" "<<i.second<<"\n";
    return 0;
}