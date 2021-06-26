#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,m,u,v,x;
    cin>>n>>m;
    queue<int> q;
    q.push(1);
    map<int,vector<int>> edges;
    map<int,int> done;
    map<int,int> status;
    done[1]=1;
    vector<int> z={1};
    vector<int> o;
    for (int i=0;i<m;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    while (!q.empty())
    {
        x=q.front();
        q.pop();
        for (auto i : edges[x])
        {
            if (!done[i])
            {
                if (status[x])
                {
                    z.push_back(i);
                    q.push(i);
                    done[i]=1;
                }
                else
                {
                    status[i]=1;
                    o.push_back(i);
                    q.push(i);
                    done[i]=1;
                }
            }
        }
    }
    cout<<min(sz(o),sz(z))<<"\n";
    if (sz(z)<sz(o))
        for (auto i : z)
            cout<<i<<" ";
    else
        for (auto i : o)
            cout<<i<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}