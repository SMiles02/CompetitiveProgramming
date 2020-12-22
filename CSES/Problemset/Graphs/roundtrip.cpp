#include <bits/stdc++.h>
using namespace std;

const int mn = 1e5+1;
vector<int> edges[mn];
bitset<mn> done;
int p[mn],h[mn];

void buildAns(int x, int y)
{
    deque<int> d;
    d.push_back(x);
    d.push_back(y);
    while (d.front()!=d.back())
    {
        if (h[d.front()]>h[d.back()])
            d.push_front(p[d.front()]);
        else
            d.push_back(p[d.back()]);
    }
    cout<<d.size()<<"\n";
    for (int i : d)
        cout<<i<<" ";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    queue<int> q;
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            q.push(i);
            done[i]=1;
            h[i]=1;
            while (!q.empty())
            {
                x=q.front();
                q.pop();
                for (int i : edges[x])
                    if (i!=p[x])
                    {
                        if (done[i])
                        {
                            buildAns(x,i);
                            return 0;
                        }
                        q.push(i);
                        done[i]=1;
                        p[i]=x;
                        h[i]=h[x]+1;
                    }
            }
        }
    cout<<"IMPOSSIBLE";
    return 0;
}