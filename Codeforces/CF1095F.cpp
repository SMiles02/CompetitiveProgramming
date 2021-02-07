#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mn = 2e5+1;
const ll INF = 1e18;
int p[mn],sz[mn];
ll ans=0;

int find_set(int x)
{
    return x==p[x] ? x : p[x] = find_set(p[x]);
}

void merge(int a, int b, ll c)
{
    a=find_set(a);
    b=find_set(b);
    if (a^b)
    {
        if (sz[a]<sz[b])
            swap(a,b);
        sz[a]+=sz[b];
        p[b]=a;
        ans+=c;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x=0,c;
    cin>>n>>m;
    ll a[n+1],y=INF;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if (a[i]<y)
        {
            y=a[i];
            x=i;
        }
    }
    for (int i=1;i<=n;++i)
    {
        p[i]=i;
        sz[i]=1;
    }
    array<ll,3> v[m+n-1];
    for (int i=0;i<m;++i)
        cin>>v[i][1]>>v[i][2]>>v[i][0];
    c=m;
    for (int i=1;i<=n;++i)
        if (i^x)
            v[c++]={a[i]+a[x],i,x};
    sort(v, v+n+m-1);
    for (int i=0;i<n+m-1;++i)
        merge(v[i][1],v[i][2],v[i][0]);
    cout<<ans;
    return 0;
}