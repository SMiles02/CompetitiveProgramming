#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    int p[k];
    for (int i=0;i<k;++i)
    {
        cin>>p[i];
    }
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for (int i=2;i<=n;++i)
    {
        dp[i]=0;
        for (int j=0;j<k;++j)
        {
            if (i>=p[j])
            {
                if (dp[i-p[j]]==0)
                {
                    dp[i]=1;
                    break;
                }
            }
        }
    }
    for (int i=1;i<=n;++i)
    {
        if (dp[i]==1)
        {
            cout<<"W";
        }
        else
        {
            cout<<"L";
        }
    }
    return 0;
}