#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l,r;
    cin>>n;
    ll a[n+2], b[n+2], p[n+2], s[n+2];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    p[0]=0;s[n+1]=0;
    for (int i=1;i<=n;++i)
        p[i]=p[i-1]+a[i]*b[i];
    for (int i=n;i>0;--i)
        s[i]=s[i+1]+a[i]*b[i];
    ll ans=p[n],cur;
    for (int i=1;i<=n;++i)
    {
        cur=a[i]*b[i];
        for (l=i-1,r=i+1;l>0&&r<=n;--l,++r)
        {
            cur+=a[l]*b[r]+a[r]*b[l];
            ans=max(ans,p[l-1]+s[r+1]+cur);
        }
        cur=0;
        for (l=i,r=i+1;l>0&&r<=n;--l,++r)
        {
            cur+=a[l]*b[r]+a[r]*b[l];
            ans=max(ans,p[l-1]+s[r+1]+cur);
        }
    }
    cout<<ans;
    return 0;
}