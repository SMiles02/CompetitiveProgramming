#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[100006];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,t=0,ans=0;
    cin>>n;
    int a[n];
    set<int> s;
    map<int,int> m;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    for (int i : s)
        m[i]=++t;
    for (int i=0;i<n;++i)
        dp[m[a[i]]]=dp[m[a[i]]-1]+1;
    for (int i=0;i<=n+4;++i)
        ans=max(ans,dp[i]);
    cout<<n-ans;
    return 0;
}