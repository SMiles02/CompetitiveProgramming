#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

double dp[101][101][101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c;
    double ans=0;
    cin>>a>>b>>c;
    dp[a][b][c]=1;
    for (int i=a+b+c;i<298;++i)
        for (int j=0;j<100;++j)
            for (int k=0;k+j<=i&&k<100;++k)
                if (i-j-k<100)
                {
                    //cout<<j<<" "<<k<<" "<<i-j-k<<"  = "<<fixed<<setprecision(3)<<dp[j][k][i-j-k]<<"\n";
                    dp[j+1][k][i-j-k]+=(dp[j][k][i-j-k]*((double)(j)/i));
                    dp[j][k+1][i-j-k]+=(dp[j][k][i-j-k]*((double)(k)/i));
                    dp[j][k][i-j-k+1]+=(dp[j][k][i-j-k]*((double)(i-j-k)/i));
                }
    for (int i=0;i<=100;++i)
        for (int j=0;j<=100;++j)
            for (int k=0;k<=100;++k)
                if (i==100||j==100||k==100)
                    ans+=((dp[i][j][k])*(i+j+k-a-b-c));
    cout<<fixed<<setprecision(10)<<ans;
    return 0;
}