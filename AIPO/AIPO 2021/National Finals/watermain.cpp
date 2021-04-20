#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

const ll INF = 1e18;

void tle()
{
    int x=0;
    while (1)
        ++x;
}

int solve(int n, int m)
{
    map<int,int> d;
    map<int,vector<array<int,2>>> e;
    int j,p,x,y,z;
    cin>>j>>p;
    while (p--)
    {
        cin>>x>>y>>z;
        d[x]=-1;
        d[y]=-1;
        e[x].push_back({y,z});
        e[y].push_back({x,z});
    }
    d[n]=INF;
    array<int,2> a;
    priority_queue<array<int,2>> pq;
    pq.push({INF,n});
    while (!pq.empty())
    {
        a=pq.top();
        pq.pop();
        if (a[0]!=d[a[1]])
            continue;
        for (auto i : e[a[1]])
            if (min(i[1],a[0])>d[i[0]])
            {
                d[i[0]]=min(i[1],a[0]);
                pq.push({d[i[0]],i[0]});
            }
    }
    return d[m];
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n;
    vector<array<int,3>> v;
    for (int i=1;i<=n;++i)
    {
        m=i+1;
        if (i==n)
            m=1;
        v.push_back({solve(i,m),i,m});
    }
    sort(v.begin(), v.end());
    cout<<v[0][1]<<" "<<v[0][2]<<" "<<v[1][0];
    return 0;
}