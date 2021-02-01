#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mn = 1e5+69;
int n,k,edges[mn];
ll m;
vector<int> v;
vector<array<int,2>> order[mn];
bitset<mn> done;

void dfs(int c)
{
    done[c]=1;
    v.push_back(c);
    if (!done[edges[c]])
        dfs(edges[c]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>m;
    set<int> reach[n+1];
    int a[n+1],b[k][2],x,y=m/k,z=m%k;
    for (int i=1;i<=n;++i)
    {
        reach[i].insert(i);
        a[i]=i;
    }
    for (int i=0;i<k;++i)
        for (int j=0;j<2;++j)
            cin>>b[i][j];
    for (int i=0;i<k;++i)
    {
        if (reach[a[b[i][0]]].find(b[i][1])==reach[a[b[i][0]]].end())
        {
            order[a[b[i][0]]].push_back({i,b[i][1]});
            reach[a[b[i][0]]].insert(b[i][1]);
        }
        if (reach[a[b[i][1]]].find(b[i][0])==reach[a[b[i][1]]].end())
        {
            order[a[b[i][1]]].push_back({i,b[i][0]});
            reach[a[b[i][1]]].insert(b[i][0]);
        }
        swap(a[b[i][0]],a[b[i][1]]);
    }
    for (int i=1;i<=n;++i)
        edges[a[i]]=i;
    int ans[n+1];
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            v.clear();
            dfs(i);
            x=v.size();
            if (x<=y)
            {
                for (int j : v)
                    for (int K : reach[j])
                        reach[i].insert(K);
                ans[i]=reach[i].size();
                for (int j : v)
                    ans[j]=ans[i];
                continue;
            }
            int sol=0,ext=0;
            map<int,int> mp;
            for (int j=0;j<y;++j)
                for (int K : reach[v[j]])
                    if (++mp[K]==1)
                        ++sol;
            for (array<int,2> K : order[v[y]])
            {
                if (K[0]>=z)
                    break;
                if (mp[K[1]]==0)
                    ++ext;
            }
            ans[i]=sol+ext;
            for (int j=1;j<x;++j)
            {
                for (int K : reach[v[j-1]])
                    if (--mp[K]==0)
                        --sol;
                for (int K : reach[v[(j+y-1)%x]])
                    if (++mp[K]==1)
                        ++sol;
                ext=0;
                for (array<int,2> K : order[v[(j+y)%x]])
                {
                    if (K[0]>=z)
                        break;
                    if (mp[K[1]]==0)
                        ++ext;
                }
                ans[v[j]]=sol+ext;
            }
        }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<"\n";
    return 0;
}