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

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

ll a[100008];
ll maxCur[100008];
ll minCur[100008];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin>>n;
    minCur[n+1]=0;
    maxCur[n+1]=0;
    ll maxNodes[100005];
    ll ans[n+1];
    ll tot;
    for (int i=0;i<=n;++i)
        cin>>a[i];
    maxNodes[0]=1;
    for (int i=1;i<31;++i)
        maxNodes[i]=maxNodes[i-1]*2;
    for (int i=31;i<100005;++i)
        maxNodes[i]=maxNodes[i-1];
    minCur[n+1]=0;
    maxCur[n+1]=0;
    for (int i=n;i>=0;--i)
    {
        if (((minCur[i+1]+1)/2)+a[i]>maxNodes[i])
        {
            cout<<-1;
            return 0;
        }
        minCur[i]=max(((minCur[i+1]+1)/2)+a[i],1);
        maxCur[i]=max(1,min(maxNodes[i],maxCur[i+1]+a[i]));
    }
    ans[0]=maxCur[0]-a[0];
    tot=ans[0]+a[0];
    for (int i=1;i<=n;++i)
    {
        ans[i]=min(ans[i-1]*2,maxCur[i])-a[i];
        tot+=ans[i]+a[i];
    }
    cout<<tot;
    return 0;
}