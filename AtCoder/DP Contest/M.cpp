#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1, MOD = 1e9+7;
int dp[101][N], p[N];

int add(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int sub(int a, int b) {
    return add(a,MOD-b);
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x;
    cin>>n>>k;
    dp[0][0]=p[0]=1;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        for (int j=1;j<=k;++j)
            p[j]=add(p[j-1],dp[i-1][j]);
        for (int j=0;j<=k;++j)
        {
            if (j-x-1<0)
                dp[i][j]=p[j];
            else
                dp[i][j]=sub(p[j],p[j-x-1]);
        }
    }
    cout<<dp[n][k];
    return 0;
}