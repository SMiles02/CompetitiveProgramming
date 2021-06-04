#include <bits/stdc++.h>
using namespace std;

const int S = 317, N = 1e5+1;
int dp[N+S][S], ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,a,l,d;
    cin>>n>>k;
    while (k--)
    {
        cin>>a>>l>>d;
        if (d<S)
        {
            ++dp[a][d];
            --dp[a+l*d][d];
        }
        else
            for (int i=a;i<a+l*d;i+=d)
                ++ans[i];
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<S;++j)
        {
            ans[i]+=dp[i][j];
            dp[i+j][j]+=dp[i][j];
        }
        cout<<ans[i]<<" ";
    }
    return 0;
}