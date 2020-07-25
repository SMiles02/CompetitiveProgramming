#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,t,ans=0,cur;
    cin>>n>>t;
    int a[n*t];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=n;i<n*t;++i)
        a[i]=a[i-n];
    int dp[n*t];
    for (int i=0;i<n*t;++i)
    {
        dp[i]=1;
        for (int j=0;j<i;++j)
            if (a[j]<=a[i])
                dp[i]=max(dp[i],dp[j]+1);
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
    for (int i=n-1;i+1;--i)
    {
        if (dp[i]==ans)
        {
            stack<int> s;
            cur=i;
            s.push(i);
            while (dp[cur]>1)
                for (int j=cur-1;j+1;--j)
                    if (a[j]<=a[cur]&&dp[j]==dp[cur]-1)
                    {
                        cur=i;
                        s.push(i);
                        break;
                    }
            while (sz(s))
            {
                cout<<a[s.top()]<<" ";
                s.pop();
            }
            break;
        }
    }
    return 0;
}