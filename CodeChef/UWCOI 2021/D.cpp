#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+7;
ll bit[mn];

void update(int i, int d)
{
    while (i<mn)
    {
        bit[i]+=d;
        i+=(i&-i);
    }
}

ll pre(int i)
{
    ll r=0;
    while (i)
    {
        r+=bit[i];
        i-=(i&-i);
    }
    return r;
}

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,a,b,c,d;
    cin>>n>>m>>k;
    ll ans=0,x=0;
    while (k--)
    {
        cin>>a>>b>>c>>d;
        ans+=abs(a-c)+abs(b-d);
        update(min(b,d),abs(a-c));
        update(max(b,d)+1,-abs(a-c)); 
    }
    for (int i=1;i<mn;++i)
        x=max(x,pre(i));
    cout<<2*ans-x;
    return 0;
}