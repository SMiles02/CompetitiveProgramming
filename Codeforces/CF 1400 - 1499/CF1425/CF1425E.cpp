#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,mini=1e7;
    ll ans=0, p=0;
    cin>>n>>k;
    int a[n],d[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>d[i];
    if (k==0)
    {
        for (int i=n-1;i>=0;--i)
        {
            p+=a[i];
            ans=max(ans,p-d[i]);
        }
        cout<<ans;
        return 0;
    }
    if (k>1)
    {
        for (int i=0;i+1<n;++i)
        {
            p+=a[i];
            mini=min(mini,d[i]);
        }
        cout<<max(0,max(a[n-1]-d[n-1],p-mini+a[n-1]));
        return 0;
    }
    return 0;
}