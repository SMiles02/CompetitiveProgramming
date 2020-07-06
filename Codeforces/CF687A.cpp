#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,vector<int>> edges;
map<int,int> done;
vector<int> x;
vector<int> y;
int gucci=1;

void dfs(int cur)
{
    //cout<<cur<<" "<<done[cur]<<"\n";
    int k=sz(edges[cur]);
    for (int i=0;i<k;++i)
    {
        if (done[edges[cur][i]])
        {
            if (done[edges[cur][i]]+done[cur]!=3)
            {
                gucci=0;
            }
        }
        else
        {
            done[edges[cur][i]]=3-done[cur];
            if (done[edges[cur][i]]==1)
            {
                x.push_back(edges[cur][i]);
            }
            else
            {
                y.push_back(edges[cur][i]);
            }
            dfs(edges[cur][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i=1;i<=n;++i)
    {
        if (!done[i])
        {
            done[i]=1;
            x.push_back(i);
            dfs(i);
        }
    }
    if (!gucci)
    {
        cout<<-1;
        return 0;
    }
    cout<<sz(x)<<"\n";
    for (int i=0;i<sz(x);++i)
    {
        cout<<x[i]<<" ";
    }
    cout<<"\n"<<sz(y)<<"\n";
    for (int i=0;i<sz(y);++i)
    {
        cout<<y[i]<<" ";
    }
    return 0;
}