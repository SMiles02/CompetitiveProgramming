#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m;
bool edges[401][401];
int done[401];

int bfs(vector<int> v, int curRound)
{
    vector<int> w;
    int k=sz(v);
    for (int i=0;i<k;++i)
    {
        if (v[i]==n)
        {
            return curRound;
        }
        for (int j=1;j<=n;++j)
        {
            if (edges[v[i]][j]&&!done[j])
            {
                done[j]=1;
                w.push_back(j);
            }
        }
    }
    if (sz(w))
    {
        return bfs(w,curRound+1);
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int u,v;
    vector<int> w={1};
    cin>>n>>m;
    while (m--)
    {
        cin>>u>>v;
        edges[u][v]=1;
        edges[v][u]=1;
    }
    done[1]=1;
    if (!edges[1][n])
    {
        cout<<bfs(w,0);
        return 0;
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
        {
            edges[i][j]=1-edges[i][j];
        }
    }
    cout<<bfs(w,0);
    return 0;
}