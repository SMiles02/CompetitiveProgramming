#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m,ans=0;
map<int,vector<int>> edges;
map<int,int> done;
vector<int> cats={0};

void dfs(int cur, int catsEncountered)
{
    done[cur]=1;
    //cout<<cur<<"!\n";
    if (cats[cur])
    {
        ++catsEncountered;
        if (catsEncountered>m)
        {
            return;
        }
    }
    else
    {
        catsEncountered=0;
    }
    if (sz(edges[cur])==1&&cur>1)
    {
        //cout<<"goodrest: "<<cur<<"\n";
        ++ans;
        return;
    }
    for (int i=0;i<sz(edges[cur]);++i)
    {
        if (!done[edges[cur][i]])
        {
            dfs(edges[cur][i],catsEncountered);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k,a,b;
    cin>>n>>m;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        cats.push_back(k);
    }
    for (int i=1;i<n;++i)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}