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
    int n,a,b,p;
    ll ans=0;
    cin>>n;
    set<int> days;
    map<int,ll> dp;
    map<int,vector<pair<int,int>>> m;
    for (int i=0;i<n;++i)
    {
        cin>>a>>b>>p;
        days.insert(a-1);
        days.insert(b);
        m[b].push_back({a-1,p});
    }
    for (int i : days)
    {
        for (auto j : m[i])
            ans=max(ans,dp[j.first]+j.second);
        dp[i]=ans;
    }
    cout<<ans;
    return 0;
}