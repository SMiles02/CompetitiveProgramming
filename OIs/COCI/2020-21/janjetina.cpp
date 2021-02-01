#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int mn = 1e5+7;
int k;
ll ans=0;
vector<pii> edges[mn];

void dfs(int c, int p, int h, int m)
{
    if (m-h>=k)
        ++ans;
    for (pii i : edges[c])
        if (i.f!=p)
            dfs(i.f,c,h+1,max(m,i.s));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,z;
    cin>>n>>k;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y>>z;
        edges[x].push_back({y,z});
        edges[y].push_back({x,z});
    }
    for (int i=1;i<=n;++i)
        dfs(i,0,0,0);
    cout<<ans;
    return 0;
}