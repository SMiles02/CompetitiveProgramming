#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e6;
ll seg[N*4][2];

ll f(ll a, ll b, int x)
{
    return a*x+b;
}

void build(int i, int l, int r, ll a, ll b)
{
    seg[i][0]=a;
    seg[i][1]=b;
    if (l==r)
        return;
    build(i*2+1,l,l+(r-l)/2,a,b);
    build(i*2+2,l+(r-l)/2+1,r,a,b);
}

void update(int i, int l, int r, ll a, ll b)
{
    if (f(a,b,l)>=f(seg[i][0],seg[i][1],l)&&f(a,b,r)>=f(seg[i][0],seg[i][1],r))
        return;
    if (f(a,b,l)<f(seg[i][0],seg[i][1],l)&&f(a,b,r)<f(seg[i][0],seg[i][1],r))
    {
        seg[i][0]=a;
        seg[i][1]=b;
        return;
    }
    update(i*2+1,l,l+(r-l)/2,a,b);
    update(i*2+2,l+(r-l)/2+1,r,a,b);
}

ll query(int i, int l, int r, int x)
{
    if (x<l||r<x)
        return 1e18;
    if (l==r)
        return f(seg[i][0],seg[i][1],x);
    return min({f(seg[i][0],seg[i][1],x),query(i*2+1,l,l+(r-l)/2,x),query(i*2+2,l+(r-l)/2+1,r,x)});
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    ll c;
    cin>>n>>c;
    ll dp[n];
    dp[0]=0;
    cin>>k;
    build(0,1,N,-2*k,1LL*k*k);
    for (int i=1;i<n;++i)
    {
        cin>>k;
        dp[i]=c+1LL*k*k+query(0,1,N,k);
        update(0,1,N,-2*k,dp[i]+1LL*k*k);
    }
    cout<<dp[n-1];
    return 0;
}