#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=100000000;
int dp[101][101][2];

//[turn][foot/horsemen used][in a row]

int add(int a, int b)
{
    return (a+b)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    dp[n1][n2][0]=1;
    dp[n1][n2][1]=1;
    for (int turn=n1+n2;turn>0;--turn)
        for (int a=n1;a>=0;--a)
            for (int b=n2;b>=0;--b)
            {
                if (a+b==turn)
                {
                    for (int i=1;a-i>=0&&i<=k1;++i)
                        dp[a-i][b][1]=add(dp[a-i][b][1],dp[a][b][0]);
                    for (int i=1;b-i>=0&&i<=k2;++i)
                        dp[a][b-i][0]=add(dp[a][b-i][0],dp[a][b][1]);
                }
            }
    cout<<add(dp[0][0][0],dp[0][0][1]);
    return 0;
}