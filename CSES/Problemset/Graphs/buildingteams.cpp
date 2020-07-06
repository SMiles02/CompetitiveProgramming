#include <bits/stdc++.h>
using namespace std;
 
const int H=1e5+1;
vector<int> edges[H];
int done[H];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,v;
    cin>>n>>m;
    while (m--)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    queue<int> q;
    for (int i=1;i<=n;++i)
    {
        if (!done[i])
        {
            done[i]=1;
            q.push(i);
            while (!q.empty())
            {
                v=q.front();
                q.pop();
                for (int x : edges[v])
                {
                    if (!done[x])
                    {
                        done[x]=3-done[v];
                        q.push(x);
                    }
                    else if (done[x]+done[v]!=3)
                    {
                        cout<<"IMPOSSIBLE";
                        return 0;
                    }
                }
            }
        }
        cout<<done[i]<<" ";
    }
    