#include <bits/stdc++.h>
using namespace std;

bitset<200001> dp;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,w,k;
    cin>>n>>w;
    dp[0]=1;
    while (n--)
    {
        cin>>k;
        dp|=dp<<k;
    }
    if (dp[w])
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}