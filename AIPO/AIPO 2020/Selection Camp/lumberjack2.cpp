#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void CutDown(int index, int direction);

/**void CutDown(int index, int direction)
{
    cout<<index<<" "<<direction<<"\n";
}**/

void CutPlan(int N, int height[])
{
    int dp[N+1],INF=1e9+7;
    pair<int,int> moves[N+1];
    dp[0]=0;
    for (int i=1;i<=N;++i)
        dp[i]=INF;
    for (int i=1;i<=N;++i)
    {
        if (height[i-1]==1)
            if (dp[i-1]+i<dp[i])
            {
                dp[i]=dp[i-1]+1;
                moves[i]={i,0};
            }
        else
        {
            if (dp[i-2]+1<dp[i])
            {
                dp[i]=dp[i-2]+1;
                moves[i]={i,0};
            }
            if (dp[i])
        }
    }
}

/**int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int h[n];
    for (int i=0;i<n;++i)
        cin>>h[i];
    CutPlan(n,h);
    return 0;
}**/