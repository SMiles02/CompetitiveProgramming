#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define f first
#define s second
using namespace std;

pair<int,ll> p[3];

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

int min(int a, int b, int c)
{
    if (a<=b&&a<=c)
        return a;
    if (b<c)
        return b;
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x,y,z;
    cin>>x>>y>>z;
    int a[400000];
    cin>>a[0];
    p[0].f=p[0].s=a[0];
    for (int i=1;i<x;++i)
    {
        cin>>a[i];
        p[0].f=min(p[0].f,a[i]);
        p[0].s+=a[i];
    }
    p[1].f=p[1].s=a[0];
    for (int i=1;i<y;++i)
    {
        cin>>a[i];
        p[1].f=min(p[1].f,a[i]);
        p[1].s+=a[i];
    }
    p[2].f=p[2].s=a[0];
    for (int i=1;i<z;++i)
    {
        cin>>a[i];
        p[2].f=min(p[2].f,a[i]);
        p[2].s+=a[i];
    }
    ll ans=p[0].s+p[1].s+p[2].s;
    if (x==1&&y==1&&z==1)
    {
        cout<<ans-2*min(p[0].f,p[1].f,p[2].f);
        return 0;
    }
    return 0;
}