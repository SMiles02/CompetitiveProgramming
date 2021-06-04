#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

const int N = 3e5+1, INF = 1e9;
int m, a[N], ans[N], p[N];
char c[N];
bitset<N> done;
pair<pair<int,char>,int> b[N];

int dt(int x, int y)
{
    if (c[x]=='R'&&c[y]=='L')
        return (a[y]-a[x])/2;
    if (c[x]=='L'&&c[y]=='L')
        return (a[x]+a[y])/2;
    if (c[x]=='R'&&c[y]=='R')
        return (m*2-a[x]-a[y])/2;
    return (m*2+a[x]-a[y])/2;
}

void solve()
{
    int n,x;
    cin>>n>>m;
    set<int> s1, s2;
    s1.insert(0);
    s2.insert(0);
    s1.insert(INF);
    s2.insert(INF);
    vector<int> v,w;
    for (int i=1;i<=n;++i)
    {
        cin>>b[i].first.first;
        b[i].second=i;
        ans[i]=-1;
        done[i]=0;
    }
    for (int i=1;i<=n;++i)
        cin>>b[i].first.second;
    sort(b+1,b+n+1);
    for (int i=1;i<=n;++i)
        a[i]=b[i].first.first,c[i]=b[i].first.second,p[i]=b[i].second;
    for (int i=1;i<=n;++i)
    {
        if (a[i]&1)
        {
            v.push_back(i);
            s1.insert(i);
        }
        else
        {
            w.push_back(i);
            s2.insert(i);
        }
    }
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> pq;
    for (int i=1;i<sz(v);++i)
        pq.push({dt(v[i-1],v[i]),v[i-1],v[i]});
    for (int i=1;i<sz(w);++i)
        pq.push({dt(w[i-1],w[i]),w[i-1],w[i]});
    array<int,3> t;
    while (!pq.empty())
    {
        t=pq.top();
        pq.pop();
        if (done[t[1]]&&done[t[2]])
            continue;
        if (done[t[2]])
        {
            if (a[t[1]]&1)
                x=*s1.upper_bound(t[1]);
            else
                x=*s2.upper_bound(t[1]);
            if (x!=0&&x!=INF)
                pq.push({dt(t[1],x),t[1],x});
            continue;
        }
        if (done[t[1]])
        {
            if (a[t[2]]&1)
                x=*--s1.lower_bound(t[2]);
            else
                x=*--s2.lower_bound(t[2]);
            if (x!=0&&x!=INF)
                pq.push({dt(x,t[2]),x,t[2]});
            continue;
        }
        ans[p[t[1]]]=ans[p[t[2]]]=t[0];
        done[t[1]]=done[t[2]]=1;
        if (a[t[1]]&1)
        {
            s1.erase(t[1]);
            s1.erase(t[2]);
        }
        else
        {
            s2.erase(t[1]);
            s2.erase(t[2]);
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}