#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,x;
    cin>>n;
    int dp[n+1];
    dp[0]=0;
    multiset<int> s;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        dp[i+1]=dp[i]+x;
        s.insert(x);
    }
    for (int i=1;i<n;++i)
        for (int j=i+1;j<=n;++j)
            s.erase(dp[j]-dp[i-1]); 
    cout<<n-sz(s)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}