#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2e5+1;
ll dp[mn][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll ans=0;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        for (int j=i;j<=n;j+=i)
        {
            ++dp[j][0];
            dp[j][1]+=dp[i][0];
        }
        ans+=dp[i][1];
    }
    cout<<ans;
    return 0;
}