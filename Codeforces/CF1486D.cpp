#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
const int MAXN = 2e5+7, INF = 1e9;
int n,k,arr[MAXN],mArr[MAXN],prefix[MAXN],segTree[4*MAXN];
 
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
        prefix[l]=prefix[l-1]+mArr[l];
        segTree[i]=prefix[l];
        return;
    }
    int m=l+((r-l)>>1);
    build((i<<1)+1,l,m);
    build((i<<1)+2,m+1,r);
    segTree[i]=min(segTree[(i<<1)+1],segTree[(i<<1)+2]);
}
 
int query(int i, int l, int r, int cL, int cR)
{
    if (cR<l||r<cL)
        return INF;
    if (l<=cL&&cR<=r)
        return segTree[i];
    int m=cL+((cR-cL)>>1);
    return min(query((i<<1)+1,l,r,cL,m),query((i<<1)+2,l,r,m+1,cR));
}

bool ok(int num)
{
    int ans=0;
    for (int i=1;i<=n;++i)
    {
        if (arr[i]<num)
            mArr[i]=-1;
        else
            mArr[i]=1;
    }
    build(0,0,n);
    for (int i=k;i<=n;++i)
        ans=max(ans,prefix[i]-query(0,max(0,i-n),i-k,0,n));
    return min(1,ans);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>arr[i];
    int l=1,r=n,m;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (ok(m))
            l=m;
        else
            r=m-1;
    }
    cout<<l;
    return 0;
}