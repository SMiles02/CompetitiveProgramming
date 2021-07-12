#include <bits/stdc++.h>
using namespace std;
 
const int N = 5005;
int pos[N][N], x;
long long p[N], dp[N][N], cur;
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>p[i];
        p[i]+=p[i-1];
    }
    for (int j=1;j<=n;++j)
        for (int i=j;i;--i)
        {
            if (i==j)
            {
                pos[i][j]=i;
                continue;
            }
            cur = 1e18;
            x=-1;
            for (int k=pos[i][j-1];k<=pos[i+1][j];++k)
                if (dp[i][k]+dp[k+1][j]<cur)
                {
                    cur=dp[i][k]+dp[k+1][j];
                    x=k;
                }
            dp[i][j]=cur+p[j]-p[i-1];
            pos[i][j]=x;
        }
    cout<<dp[1][n];
    return 0;
}