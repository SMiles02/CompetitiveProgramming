#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e6+1;
int dp[N];
vector<int> d[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=2;i<N;++i)
    {
        dp[i]=1;
        for (int j : d[i])
            dp[i]=max(dp[i],dp[i/j-1]+1);
        //if (i<50)
        //    cout<<"dp_"<<i<<": "<<dp[i]<<"\n";
        for (int j=i*2;j<N;j+=i)
            d[j].push_back(i);
    }
    int t,n,ans;
    cin>>t;
    for (int i=1;i<=t;++i)
    {
        cin>>n;
        ans=1;
        for (int j : d[n])
            if (j>2)
                ans=max(ans,dp[n/j-1]+1);
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
    return 0;
}