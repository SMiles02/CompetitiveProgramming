#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
vector<int> edges[300001];

void spider()
{
    int d,k;
    cin>>d;
    for (int i=0;i<d;++i)
        cin>>k;
    if ((n-1)&1)
    {
        cout<<"-1\n";
        return;
    }
    cout<<n-1+d<<"\n";
}

void line()
{
    int d;
    cin>>d;
    ll ans=n-1+d;
    int a[d];
    for (int i=0;i<d;++i)
        cin>>a[i];
    if (d&1)
    {
        cout<<"-1\n";
        return;
    }
    sort(a,a+d);
    for (int i=0;i<d;i+=2)
        ans+=a[i+1]-a[i];
    cout<<ans<<"\n";
    return;
} 

void dfs()

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,u,v;
    bool ok;
    cin>>n>>q;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    /**if (sz(edges[1])==n-1)
    {
        while (q--)
            spider();
        return 0;
    }**/
    ok=1;
    for (int i=2;i<n;++i)
        if (sz(edges[i])!=2)
            ok=0;
    if (sz(edges[1])!=1)
        ok=0;
    if (sz(edges[n])!=1)
        ok=0;
    if (ok)
    {
        while (q--)
            line();
        return 0;
    }

    return 0;
}