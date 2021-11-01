#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[3000][3000];
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int j=0;j<n;++j)
    {
        dp[j][j]=a[j];
        for (int i=j-1;i>=0;--i)
            dp[i][j]=max(-dp[i+1][j]+a[i],-dp[i][j-1]+a[j]);
    }
    cout<<dp[0][n-1];
    return 0;
}