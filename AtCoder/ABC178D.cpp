#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod=1e9+7;
int dp[667][2001];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,pre,ans=0;
    cin>>n;
    dp[0][0]=1;
    for (int i=1;i<667;++i)
    {
        pre=0;
        for (int j=0;j<=n;++j)
        {
            if (j-3>=0)
                pre=add(pre,dp[i-1][j-3]);
            dp[i][j]=pre;
            //cout<<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<"\n";
        }
        ans=add(ans,dp[i][n]);
    }
    cout<<ans;
    return 0;
}