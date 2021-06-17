#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+7, INF = 1e9;
int n,k,w,a[N],cur,l[N],r[N];
vector<vector<int>> dp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>w;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (w==1)
    {
        sort(a+1,a+n+1,greater<int>());
        int ans=0;
        for (int i=1;i<=k;++i)
            ans+=a[i];
        cout<<ans;
        return 0;
    }
    if (k==1)
    {
        int ans=0;
        stack<int> s;
        s.push(0);
        for (int i=1;i<=n;++i)
        {
            while (a[s.top()]>=a[i])
                s.pop();
            l[i]=s.top()+1;
            s.push(i);
        }
        while (!s.empty())
            s.pop();
        s.push(n+1);
        for (int i=n;i>0;--i)
        {
            while (a[s.top()]>=a[i])
                s.pop();
            r[i]=s.top();
            s.push(i);
            ans=max(ans,min(r[i]-l[i],w)*a[i]);
        }
        cout<<ans;
        return 0;
    }
    dp.resize(k+3,vector<int>(n+3,0));
    for (int i=1;i<=k;++i)
    {
        for (int j=1;j<=n;++j)
        {
            cur=a[j];
            for (int l=j;l>max(0,j-w);--l)
            {
                cur=min(cur,a[l]);
                dp[i][j]=max(dp[i][j],dp[i-1][l-1]+cur*(j-l+1));
            }
            dp[i][j]=max(dp[i][j],dp[i][j-1]);
            //cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    cout<<dp[k][n];
    return 0;
}