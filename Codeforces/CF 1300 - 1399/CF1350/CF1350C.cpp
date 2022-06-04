#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
    return (a/gcd(a,b))*b;
}

ll n,f=0;
ll segtree[900000];
ll a[100001];

void build(int l, int r, int i)
{
    if (l==r)
    {
        segtree[i]=a[l];
        return;
    }
    build(l,l+(r-l)/2,i*2+1);
    build(l+(r-l)/2+1,r,i*2+2);
    segtree[i]=gcd(segtree[2*i+1],segtree[2*i+2]);
}

ll query(int l, int r, int curL, int curR, int i)
{
    if (l<=curL&&curR<=r)
        return segtree[i];
    if (r<curL||curR<l)
        return -1;
    int a=query(l,r,curL,curL+(curR-curL)/2,i*2+1),b=query(l,r,curL+(curR-curL)/2+1,curR,i*2+2);
    if (a==-1)
        return b;
    if (b==-1)
        return a;
    return gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    build(1,n,0);
    ll ans=lcm(query(2,n,1,n,0),query(1,n-1,1,n,0));
    for (int i=2;i<n;++i)
        ans=lcm(ans,gcd(query(1,i-1,1,n,0),query(i+1,n,1,n,0)));
    cout<<ans;
    return 0;
}