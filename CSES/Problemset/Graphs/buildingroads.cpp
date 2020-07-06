#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool done[100001];
vector<int> edges[100001];
vector<int> groups[100001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,v,g=0;
    cin>>n>>m;
    while (m--)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    queue<int> q;
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            ++g;
            done[i]=1;
            groups[g].push_back(i);
            q.push(i);
            while (!q.empty())
            {
                v=q.front();
                q.pop();
                for (int x : edges[v])
                    if (!done[x])
                    {
                        done[x]=1;
                        groups[g].push_back(x);
                        q.push(x);
                    }
            }
        }
    cout<<g-1<<"\n";
    for (int i=2;i<=g;++i)
        cout<<groups[i-1][0]<<" "<<groups[i][0]<<"\n";
    return 0;
}