#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

double ans=0;
map<int,vector<int>> edges;
map<int,int> done;

void dfs(int cur, double prob, int distance)
{
    done[cur]=1;
    int k=sz(edges[cur]);
    if (k==1)
    {
        ans+=(prob*distance);
        return;
    }
    for (int i=0;i<k;++i)
    {
        if (!done[edges[cur][i]])
        {
            dfs(edges[cur][i],prob/(k-1),distance+1);
        }
    }
    return;
}

void rootDFS()
{
    done[1]=1;
    double a=1;
    int k=sz(edges[1]);
    for (int i=0;i<k;++i)
    {
        dfs(edges[1][i],a/k,1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    rootDFS();
    cout<<setprecision(10)<<ans;
    return 0;
}