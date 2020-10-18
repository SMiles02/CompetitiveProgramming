#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN = 2e5+7;
ll prefix[MAXN],segTree[5*MAXN],INF=1e18;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

ll max(ll a, ll b)
{
    if (a<b)
        return b;
    return a;
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        if (l==0)
            return;
        cin>>prefix[l];
        prefix[l]+=prefix[l-1];
        segTree[i]=prefix[l];
        return;
    }
    int m=l+((r-l)>>1);
    build((i<<1)+1,l,m);
    build((i<<1)+2,m+1,r);
    segTree[i]=min(segTree[(i<<1)+1],segTree[(i<<1)+2]);
}

ll query(int i, int l, int r, int cL, int cR)
{
    if (cR<l||r<cL)
        return INF;
    if (l<=cL&&cR<=r)
        return segTree[i];
    int m=cL+((cR-cL)>>1);
    return min(query((i<<1)+1,l,r,cL,m),query((i<<1)+2,l,r,m+1,cR));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b;
    ll ans=-INF;
    cin>>n>>a>>b;
    build(0,0,n);
    for (int i=a;i<=n;++i)
        ans=max(ans,prefix[i]-query(0,max(0,i-b),i-a,0,n));
    cout<<ans;
    return 0;
}