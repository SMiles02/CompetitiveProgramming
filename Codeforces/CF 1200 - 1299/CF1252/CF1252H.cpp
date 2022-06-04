#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a<b) return a;
    return b;
}

ll max(ll a, ll b)
{
    if (a>b) return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll l,w,cur,ans=0;
    cin>>n;
    vector<pair<int,int>> v;
    for (int i=0;i<n;++i)
    {
        cin>>l>>w;
        ans=max(ans,1ll*l*w);
        v.push_back({min(l,w),max(l,w)});
    }
    sort(v.rbegin(), v.rend());
    cur=v[0].second;
    for (int i=1;i<n;++i)
    {
        ans=max(ans,2ll*v[i].first*min(cur,v[i].second));
        cur=max(cur,v[i].second);
    }
    cout<<ans/2;
    if (ans%2) cout<<".5";
    else cout<<".0";
    return 0;
}