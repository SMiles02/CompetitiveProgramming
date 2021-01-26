#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int mn = 1e5+7, mxn = 5*mn, INF = 1e9;
vector<pii> edges[mxn];
vector<int> col[mn];
map<pii,int> colNum;
int d[mxn];
bitset<mxn> done;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,z,c=0,ans;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y>>z;
        if (!colNum[{x,z}])
        {
            colNum[{x,z}]=++c;
            col[x].push_back(c);
        }
        if (!colNum[{y,z}])
        {
            colNum[{y,z}]=++c;
            col[y].push_back(c);
        }
        edges[colNum[{x,z}]].push_back({colNum[{y,z}],0});
        edges[colNum[{y,z}]].push_back({colNum[{x,z}],0});
    }
    for (int i=2;i<=n;++i)
    {
        ++c;
        d[c]=INF;
        for (int j : col[i])
        {
            edges[j].push_back({c,1});
            edges[c].push_back({j,0});
            d[j]=INF;
        }
    }
    deque<pii> q;
    pii p;
    for (int i : col[1])
    {
        q.push_front({i,0});
        d[i]=0;
    }
    while (!q.empty())
    {
        p=q.front();
        q.pop_front();
        if (done[p.f])
            continue;
        done[p.f]=1;
        for (pii i : edges[p.f])
        {
            if (i.s)
            {
                if (p.s+1<d[i.f])
                {
                    d[i.f]=p.s+1;
                    q.push_back({i.f,d[i.f]});
                }
            }
            else
            {
                if (p.s<d[i.f])
                {
                    d[i.f]=p.s;
                    q.push_front({i.f,d[i.f]});
                }
            }
        }
    }
    ans=INF;
    for (int i : col[n])
        ans=min(ans,d[i]);
    if (ans==INF)
        ans=-2;
    cout<<ans+1;
    return 0;
}