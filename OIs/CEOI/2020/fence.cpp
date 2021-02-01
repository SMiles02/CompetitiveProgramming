#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
int mod=1e9+7, inv, INF=1e9+10;
int h[100001];
int w[100001];
int segTree[100001*5];

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
        return (res * a)%mod;
    return res;
}

ll add(ll a, ll b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

ll sub(ll a, ll b)
{
    a-=b;
    if (a<0)
        a+=mod;
    return a;
}

ll f(ll x)
{
    x*=(x+1);
    x%=mod;
    x*=inv;
    return x%mod;
}

ll calc(ll a, ll b)
{
    return (f(a%mod)*f(b%mod))%mod;
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        segTree[i]=h[l];
        //cout<<i<<" "<<l<<" "<<r<<": "<<segTree[i]<<"\n";
        return;
    }
    int m=l+((r-l)>>1);
    build((i<<1)+1,l,m);
    build((i<<1)+2,m+1,r);
    segTree[i]=min(segTree[(i<<1)+1],segTree[(i<<1)+1]);
    //cout<<i<<" "<<l<<" "<<r<<": "<<segTree[i]<<"\n";
}

int query(int i, int cL, int cR, int l, int r)
{
    if (r<cL||cR<l)
        return INF;
    if (l<=cL&&cR<=r)
        return segTree[i];
    int m=cL+((cR-cL)>>1);
    return min(query((i<<1)+1,cL,m,l,r),query((i<<1)+2,m+1,cR,l,r));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    inv=binpow(2,mod-2);
    int n,m;
    cin>>n;
    ll pre[n+1],ans=0;
    for (int i=1;i<=n;++i)
        cin>>h[i];
    for (int i=1;i<=n;++i)
        cin>>w[i];
    build(0,1,n);
    pre[0]=0;
    for (int i=1;i<=n;++i)
        pre[i]=add(pre[i-1],w[i]);
    for (int i=1;i<=n;++i)
    {
        for (int j=i+1;j<=n;++j)
        {
            m=query(0,1,n,i,j);
            ans=add(ans,sub(add(calc(m,sub(pre[j],pre[i-1])),calc(m,sub(pre[j-1],pre[i]))),add(calc(m,sub(pre[j-1],pre[i-1])),calc(m,sub(pre[j],pre[i])))));
        }
        ans=add(ans,calc(h[i],w[i]));
    }
    cout<<ans;
    return 0;
}