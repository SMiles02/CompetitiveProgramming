#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int sieve[100001];

ll max(ll a, ll b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}

void sieveBuild()
{
    sieve[1]=1;
    for (int i=2;i<100001;++i)
    {
        if (!sieve[i])
        {
            for (int j=2;i*j<100001;++j)
            {
                sieve[i*j]=1;
            }
        }
    }
}

map<int,vector<pair<int,int>>> edges;
map<int,int> done;
ll ans=0;

void dfs(int cur, ll distanceRN)
{
    ans=max(ans,distanceRN);
    //cout<<"cur = "<<cur<<"\n";
    done[cur]=1;
    int k=sz(edges[cur]);
    for (int i=0;i<k;++i)
    {
        if (!done[edges[cur][i].first])
        {
            dfs(edges[cur][i].first,distanceRN+edges[cur][i].second);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    sieveBuild();
    int n,u,v,w;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v>>w;
        if (!sieve[w])
        {
            edges[u].push_back({v,w});
            edges[v].push_back({u,w});
        }
    }
    for (int i=1;i<=n;++i)
    {
        if (sz(edges[i])==1)
        {
            dfs(i,0);
            done.clear();
        }
    }
    cout<<ans;
    return 0;
}