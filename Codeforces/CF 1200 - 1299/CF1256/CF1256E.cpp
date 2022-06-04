#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const ll INF = 1e18;

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,b=0,cur;
    cin>>n;
    int ans[n];
    pair<int,int> a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a,a+n);
    ll dp[n+1];
    dp[0]=0;
    for (int i=1;i<=n;++i)
    {
        dp[i]=INF;
        if (i>2)
            dp[i]=min(dp[i],dp[i-3]+a[i-1].first-a[i-3].first);
        if (i>3)
            dp[i]=min(dp[i],dp[i-4]+a[i-1].first-a[i-4].first);
        if (i>4)
            dp[i]=min(dp[i],dp[i-5]+a[i-1].first-a[i-5].first);
    }
    //for (int i=0;i<=n;++i)
        //cout<<dp[i]<<" ";
    //cout<<"\n";
    cout<<dp[n]<<" ";
    cur=n;
    while (cur>0)
    {
        //cout<<cur<<" is  "<<dp[cur]<<"\n";
        for (int i=3;i<6;++i)
        {
            //cout<<dp[cur-i]<<"!!!\n";
            //cout<<dp[cur-i]<<" "<<a[cur-1].first<<" -"<<a[cur-i].first<<"\n";
            //cout<<dp[cur-i]+a[cur-1].first-a[cur-i].first<<" /////!!!\n";
            if (dp[cur]==dp[cur-i]+a[cur-1].first-a[cur-i].first)
            {
                //cout<<"in\n";
                ++b;
                for (int j=cur-i+1;j<=cur;++j)
                    ans[a[j-1].second]=b;
                cur-=i;
                break;
            }
        }
    }
    cout<<b<<"\n";
    for (int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    return 0;
}