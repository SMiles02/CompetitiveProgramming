#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int totalRed=0,totalBlue=0,ans;
map<int,vector<int>> edges;
bool done[300001];
bool isRed[300001];
bool isBlue[300001];

pair<int,int> dfs(int cur)
{
    done[cur]=1;
    pair<int,int> rb;
    int redSum=isRed[cur],blueSum=isBlue[cur],k=sz(edges[cur]);
    for (int i=0;i<k;++i)
    {
        if (!done[edges[cur][i]])
        {
            rb=dfs(edges[cur][i]);
            redSum+=rb.first;
            blueSum+=rb.second;
        }
    }
    if ((redSum==0&&blueSum==totalBlue)||(redSum==totalRed&&blueSum==0)) ++ans;
    return {redSum,blueSum};
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,u,v,k;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        if (k==1)
        {
            isRed[i]=1;
            ++totalRed;
        }
        if (k==2)
        {
            isBlue[i]=1;
            ++totalBlue;
        }
    }
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    pair<int,int> pp=dfs(1);
    cout<<ans;
    return 0;
}