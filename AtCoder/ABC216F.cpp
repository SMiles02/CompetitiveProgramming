#include <bits/stdc++.h>
using namespace std;

const int N = 5001, MOD = 998244353;
int dp[2][N];
vector<int> v[N];

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,ans=0;
    cin>>n;
    int a[n];
    dp[0][0]=1;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
    {
        cin>>x;
        v[a[i]].push_back(x);
    }
    for (int i=1;i<N;++i)
        if (!v[i].empty())
        {
            for (int j : v[i])
                for (int k=N-1;k>=j;--k)
                    dp[1][k]=add(dp[1][k],add(dp[0][k-j],dp[1][k-j]));
            for (int j=0;j<N;++j)
            {
                if (j<=i)
                    ans=add(ans,dp[1][j]);
                dp[0][j]=add(dp[0][j],dp[1][j]);
                dp[1][j]=0;
            }
        }
    cout<<ans;
    return 0;
}