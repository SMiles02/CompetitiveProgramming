#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,k;
    cin>>n>>a>>b;
    double dp[6*n+1][n+1]={0};
    dp[0][0]=1;
    double sixth=1;
    sixth/=6;
    for (int i=1;i<n+1;++i)
    {
        for (int j=1;j<6*n+1;++j)
        {
            dp[j][i]=sixth*dp[j-1][i-1];
            if (j>1)
            {
                dp[j][i]+=(dp[j-2][i-1]*sixth);
            }
            if (j>2)
            {
                dp[j][i]+=(dp[j-3][i-1]*sixth);
            }
            if (j>3)
            {
                dp[j][i]+=(dp[j-4][i-1]*sixth);
            }
            if (j>4)
            {
                dp[j][i]+=(dp[j-5][i-1]*sixth);
            }
            if (j>5)
            {
                dp[j][i]+=(dp[j-6][i-1]*sixth);
            }
        }
    }
    double ans=0;
    for (int i=a;i<=b;++i)
    {
        ans+=dp[i][n];
    }
    //cout<<setprecision(10)<<ans<<"\n";
    k=ans*10000000;
    if (k%10>4)
    {
        k+=10;
    }
    k/=10;
    //cout<<k<<"\n";
    k=max(k,1);
    if (k==1)
    {
        cout<<"0.000001";
        return 0;
    }
    ans=k;
    ans/=1000000;
    cout<<setprecision(6)<<ans;
    if (k%10==0)
    {
        cout<<0;
    }
    return 0;
}