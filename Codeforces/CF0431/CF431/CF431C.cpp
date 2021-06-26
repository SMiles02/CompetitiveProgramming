#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1000000007;
ll dp[101][2]={};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,d;
    cin>>n>>k>>d;
    dp[0][0]=1;
    for (int i=1;i<101;++i)
    {
        for (int j=1;j<(k+1)&&(i-j+1);++j)
        {
            dp[i][1]+=dp[i-j][1];
            if (j>=d)
            {
                dp[i][1]+=dp[i-j][0];
            }
            else
            {
                dp[i][0]+=dp[i-j][0];
            }
            dp[i][0]%=mod;
            dp[i][1]%=mod;
        }
    }
    cout<<dp[n][1];
    return 0;
}