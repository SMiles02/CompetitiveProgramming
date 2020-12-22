#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[13][201];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    dp[0][0]=1;
    for (int i=1;i<13;++i)
        for (int j=0;j<=n;++j)
            for (int k=0;k<j;++k)
                dp[i][j]+=dp[i-1][k];
    cout<<dp[12][n];
    return 0;
}