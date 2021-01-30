#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

const int mn = 1e5;
int dp[mn+1][35];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,h,w,n;
    cin>>a>>b>>h>>w>>n;
    if ((h>=a&&w>=b)||(w>=a&&h>=b))
    {
        cout<<0;
        return 0;
    }
    vector<int> v(n);
    for (int i=0;i<n;++i)
        cin>>v[i];
    sort(v.rbegin(), v.rend());
    dp[h][0]=w;
    for (int i=0;i<min(n,34);++i)
    {
        for (int j=1;j<=mn;++j)
        {
            if (1LL*j*v[i]>mn)
                dp[mn][i+1]=max(dp[mn][i+1],dp[j][i]);
            else
                dp[j*v[i]][i+1]=max(dp[j*v[i]][i+1],dp[j][i]);
            dp[j][i+1]=max(dp[j][i+1],min(1LL*dp[j][i]*v[i],mn));
        }
        for (int j=1;j<=mn;++j)
            if ((j>=a&&dp[j][i+1]>=b)||(j>=b&&dp[j][i+1]>=a))
            {
                cout<<i+1;
                return 0;
            }
    }
    cout<<-1;
    return 0;
}