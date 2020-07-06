#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x;
    cin>>n>>q;
    ll dp[n+1];
    dp[0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        dp[i]=dp[i-1]+x;
    }
    while (q--)
    {
        cin>>n>>x;
        cout<<dp[x]-dp[n-1]<<"\n";
    }
    return 0;
}