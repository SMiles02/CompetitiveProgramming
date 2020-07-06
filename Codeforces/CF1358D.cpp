#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
ll sumTo(ll n)
{
    return (n*(n+1))/2;
}
 
ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}
 
ll n,x,a[400007],l,r,m;
ll prefix[400007],monthly[400007],ans=0;
 
void check(ll k)
{
    if (a[k-n]>=x)
    {
        ans=max(sumTo(a[k-n])-sumTo(a[k-n]-x),ans);
        return;
    }
    l=1;r=k;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (prefix[k]-prefix[m-1]>x)
            l=m+1;
        else
            r=m;
    }
    //cout<<k-n<<": "<<monthly[k]-monthly[l-1]<<" "<<sumTo(a[l-1])-sumTo(a[l-1]-(x-(prefix[k]-prefix[l-1])))<<"\n";
    ans=max(ans,monthly[k]-monthly[l-1]+sumTo(a[l-1])-sumTo(a[l-1]-(x-(prefix[k]-prefix[l-1]))));
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>x;
    for (ll i=1;i<=n;++i)
        cin>>a[i];
    prefix[0]=0;
    monthly[0]=0;
    for (ll i=n+1;i<=2*n;++i)
        a[i]=a[i-n];
    for (ll i=1;i<=2*n;++i)
    {
        prefix[i]=prefix[i-1]+a[i];
        monthly[i]=monthly[i-1]+sumTo(a[i]);
        //cout<<i<<": "<<monthly[i]<<"\n";
    }
    for (ll i=2*n;i>n;--i)
        check(i);
    cout<<ans;
    return 0;
}