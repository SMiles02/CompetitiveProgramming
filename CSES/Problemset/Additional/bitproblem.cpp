#include <bits/stdc++.h>
using namespace std;
 
int dp[2][1<<20];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ++dp[0][a[i]];
        ++dp[1][((1<<20)-1)^a[i]];
    }
    for (int k=0;k<2;++k)
        for (int j=0;j<20;++j)
            for (int i=0;i<(1<<20);++i)
                if (i&(1<<j))
                    dp[k][i]+=dp[k][i^(1<<j)];
    for (int i=0;i<n;++i)
        cout<<dp[0][a[i]]<<" "<<dp[1][((1<<20)-1)^a[i]]<<" "<<n-dp[0][((1<<20)-1)^a[i]]<<"\n";
    return 0;
}