#include <bits/stdc++.h>
using namespace std;

const int N = 600, INF = 2e9;
int n, v, d[N];
vector<array<int,2>> e[N];
bitset<N> done;

void dijkstra(int s)
{
    done.reset();
    for (int i=0;i<n;++i)
        d[i]=INF;
    for (auto i : e[s])
        if (i[0]<n)
            d[i[0]]=i[1];
    for (int i=0;i<n;++i)
    {
        v=-1;
        for (int j=0;j<n;++j)
            if (!done[j]&&(v==-1||d[j]<d[v]))
                v=j;
        done[v]=1;
        for (auto j : e[v])
        {
            if (j[0]<n)
                d[(j[0]+d[v])%n]=min(d[(j[0]+d[v])%n],d[v]+j[1]);
            else
                d[j[0]-n]=min(d[j[0]-n],d[v]+j[1]);
        }
    }
    for (int i=0;i<n;++i)
    {
        if (i==s)
            cout<<"0 ";
        else
            cout<<d[i]<<" ";
    }
    cout<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,a,b,c;
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b>>c;
        e[a].push_back({b,c});
    }
    for (int i=0;i+1<n;++i)
        e[i].push_back({i+n+1,1});
    e[n-1].push_back({n,1});
    for (int i=0;i<n;++i)
        dijkstra(i);
    return 0;
}