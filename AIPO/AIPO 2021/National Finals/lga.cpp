#include <bits/stdc++.h>
using namespace std;

const int N = 205;
int dp[N][N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,ans=0;
    cin>>n>>m;
    int a[n][m];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            x=0;
            for (int k=j;k<m;++k)
            {
                if (a[i][k]==0)
                    ++x;
                else if (a[i][k]==5)
                    --x;
                for (int l=0;l<=i;++l)
                {
                    dp[j][k][l]+=x;
                    if (dp[j][k][l]==0)
                        ans=max(ans,(k-j+1)*(i-l+1));
                }
            }
        }
    if (ans==0)
        cout<<"No possible chip";
    else
        cout<<ans;
    return 0;
}