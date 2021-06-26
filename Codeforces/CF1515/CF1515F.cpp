#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 3e5+1;
int pt[N],k;
ll a[N];
priority_queue<pair<ll,int>> pq;
vector<array<int,2>> e[N];
 
int find_set(int v) {
    if (v == pt[v])
        return v;
    return pt[v] = find_set(pt[v]);
}
 
void unite(int x, int y) {
    if (sz(e[x]) < sz(e[y]))
        swap(x, y);
    pt[y] = x;
    a[x] += a[y] - k;
    a[y] = 0;
    while (!e[y].empty())
    {
        if (find_set(e[y].back()[0])!=x)
            e[x].push_back(e[y].back());
        e[y].pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,t;
    ll sm=0,z;
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
    {
        pt[i]=i;
        cin>>a[i];
        sm+=a[i];
        pq.push({a[i],i});
    }
    if (sm<1LL*k*(n-1))
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for (int i=1;i<=m;++i)
    {
        cin>>x>>y;
        e[x].push_back({y,i});
        e[y].push_back({x,i});
    }
    while (!pq.empty())
    {
        x=find_set(pq.top().second);
        z=pq.top().first;
        pq.pop();
        if (a[x]!=z||a[x]==0||e[x].empty())
            continue;
        y=find_set(e[x].back()[0]);
        t=e[x].back()[1];
        e[x].pop_back();
        if (x!=y)
        {
            cout<<t<<"\n";
            unite(x,y);
        }
        x=find_set(x);
        pq.push({a[x],x});
    }
    return 0;
}