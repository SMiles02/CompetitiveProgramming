#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[200001];
int charCount[26];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=1;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        for (int j=(s[i]-'a')+1;j<26;++j)
            dp[i]=max(dp[i],charCount[j]);
        ++dp[i];
        charCount[(s[i]-'a')]=dp[i];
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    for (int i=0;i<n;++i)
        cout<<dp[i]<<" ";
    return 0;
}