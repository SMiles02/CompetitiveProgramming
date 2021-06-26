#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,vector<int>> edges;
bool done[200001];
int below[200001];
int height[200001];
vector<pair<int,int>> scores; 

void dfs(int cur, int h)
{
    done[cur]=1;
    height[cur]=h;
    int k=sz(edges[cur]);
    for (int i=0;i<k;++i)
    {
        if (!done[edges[cur][i]])
        {
            dfs(edges[cur][i],h+1);
            below[cur]+=1+below[edges[cur][i]];
        }
    }
    scores.push_back({h-below[cur],cur});
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,u,v;
    ll ans=0;
    cin>>n>>k;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0);
    sort(scores.begin(), scores.end());
    while (k--)
    {
        //cout<<scores.back().second<<": +"<<height[scores.back().second]<<" "<<below[scores.back().second]<<"\n";
        ans+=height[scores.back().second];
        ans-=below[scores.back().second];
        scores.pop_back();
    }
    cout<<ans;
    return 0;
}