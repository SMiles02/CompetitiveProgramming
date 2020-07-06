#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool done[10001];
map<int,vector<int>> edges;
int s;

void dfs(int cur)
{
    ++s;
    done[cur]=1;
    int k=sz(edges[cur]);
    for (int i=0;i<k;++i)
    {
        if (!done[edges[cur][i]])
        {
            dfs(edges[cur][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,ans=0;
    cin>>n>>m;
    bool divisible[n+1][n+1];
    while (m--)
    {
        cin>>x>>y;
        if (x!=y)
        {
            divisible[x][y]=1;
        }
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=i+1;j<=n;++j)
        {
            if (divisible[i][j]&&divisible[j][i])
            {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }
    for (int i=1;i<=n;++i)
    {
        if (!done[i])
        {
            s=0;
            dfs(i);
            ans+=min(2,s);
        }
    }
    cout<<ans;
    return 0;
}