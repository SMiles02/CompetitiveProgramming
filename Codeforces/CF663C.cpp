#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+1;
bool okB = 1, okR = 1;
bitset<N> rC,bC,d1,d2;
vector<int> v[2],r,b;
vector<array<int,2>> edges[N];

void addEdge(int x, int y, int z)
{
    edges[x].push_back({y,z});
    edges[y].push_back({x,z});
}

void blueDfs(int c, int x)
{
    d1[c]=1;
    bC[c]=x;
    v[x].push_back(c);
    for (auto i : edges[c])
    {
        if (d1[i[0]])
        {
            if (i[1]!=(bC[c]^bC[i[0]]))
                okB=0;
        }
        else
            blueDfs(i[0],x^i[1]);
    }
}

void redDfs(int c, int x)
{
    d2[c]=1;
    rC[c]=x;
    v[x].push_back(c);
    for (auto i : edges[c])
    {
        if (d2[i[0]])
        {
            if (i[1]==(rC[c]^rC[i[0]]))
                okR=0;
        }
        else
            redDfs(i[0],x^i[1]^1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    char c;
    while (m--)
    {
        cin>>x>>y>>c;
        if (c=='B')
            addEdge(x,y,0);
        else
            addEdge(x,y,1);
    }
    for (int i=1;i<=n;++i)
        if (!d1[i])
        {
            v[0].clear();v[1].clear();
            blueDfs(i,0);
            if (sz(v[0])<sz(v[1]))
                for (int j : v[0])
                    b.push_back(j);
            else
                for (int j : v[1])
                    b.push_back(j);
            v[0].clear();v[1].clear();
            redDfs(i,0);
            if (sz(v[0])<sz(v[1]))
                for (int j : v[0])
                    r.push_back(j);
            else
                for (int j : v[1])
                    r.push_back(j);
        }
    if (okR&&okB)
    {
        if (sz(r)<sz(b))
        {
            cout<<sz(r)<<"\n";
            for (int i : r)
                cout<<i<<" ";
        }
        else
        {
            cout<<sz(b)<<"\n";
            for (int i : b)
                cout<<i<<" ";
        }
    }
    else if (okR)
    {
        cout<<sz(r)<<"\n";
        for (int i : r)
            cout<<i<<" ";
    }
    else if (okB)
    {
        cout<<sz(b)<<"\n";
        for (int i : b)
            cout<<i<<" ";
    }
    else
        cout<<-1;
    return 0;
}