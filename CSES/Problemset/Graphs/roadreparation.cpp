#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

vector<pii> edges[100001];
bitset<100001> done;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,z,d=1;
    ll ans=0;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        cin>>x>>y>>z;
        edges[x].push_back({z,y});
        edges[y].push_back({z,x});
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    done[1]=1;
    for (pii i : edges[1])
        q.push(i);
    while (!q.empty())
    {
        x=q.top().f;
        y=q.top().s;
        q.pop();
        if (done[y])
            continue;
        done[y]=1;
        ans+=x;
        ++d;
        for (pii i : edges[y])
            q.push(i);
    }
    if (d!=n)
        cout<<"IMPOSSIBLE";
    else
        cout<<ans;
    return 0;
}