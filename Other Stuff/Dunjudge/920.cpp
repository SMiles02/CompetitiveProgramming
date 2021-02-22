#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<array<int,3>> a;

bool cmp(array<int,3> x1, array<int,3> x2)
{
    if (x1[1]-x1[0]<x2[1]-x2[0])
        return 1;
    return 0;
}

ll queueCase()
{
    vector<ll> dp(n);
    ll ans=0;
    for (int i=n-1;i>=0;--i)
    {
        dp[i]=a[i][2];
        for (int j=i+1;j<n;++j)
            if (a[i][0]<=a[j][0]&&a[i][1]<=a[j][1])
                dp[i]=max(dp[i],dp[j]+a[i][2]);
        ans=max(ans,dp[i]);
    }
    return ans;
}

ll stackCase()
{
    int t=0;
    set<int> s;
    for (int i=0;i<n;++i)
    {
        s.insert(a[i][0]);
        s.insert(a[i][1]);
    }
    map<int,int> m;
    for (int i : s)
        m[i]=++t;
    for (int i=0;i<n;++i)
        dp[m[a[i][0]]][m[a[i][1]]]+=a[i][2];
    for (int i=1;i<n;++i)
        for (int j=0;j<i;++j)

    for (int j=1;j<=t;++j)
        for (int i=0;i<=j;++i)
            dp[0][j]=max(dp[0][j],dp[0][i]+dp[i][j]);
    return dp[0][t];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int f;
    cin>>n>>f;
    a.resize(n);
    for (int i=0;i<n;++i)
        for (int j=0;j<3;++j)
            cin>>a[i][j];
    sort(a.begin(), a.end());
    //cout<<queueCase()<<" ";
    cout<<stackCase();
    return 0;
}