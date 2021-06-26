#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,h,l,r,k;
    cin>>n>>h>>l>>r;
    int sum[n+1];
    sum[0]=0;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        sum[i+1]=sum[i]+k;
    }
    int dp[n+1][n+1];
    dp[0][0]=0;
    for (int i=1;i<=n;++i)
    {
        if (l<=(sum[i]%h)&&(sum[i]%h)<=r)
        {
            dp[i][0]=dp[i-1][0]+1;
        }
        else
        {
            dp[i][0]=dp[i-1][0]+0;
        }
        for (int j=1;j<i;++j)
        {
            if (l<=((sum[i]-j)%h)&&((sum[i]-j)%h)<=r)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]);
            }
        }
        if (l<=((sum[i]-i)%h)&&((sum[i]-i)%h)<=r)
        {
            dp[i][i]=dp[i-1][i-1]+1;
        }
        else
        {
            dp[i][i]=dp[i-1][i-1];
        }
        //cout<<"dp["<<i<<"]["<<i<<"] = "<<dp[i][i]<<"\n";
    }
    int ans=0;
    /**for (int i=0;i<=n;++i)
    {
        cout<<"i="<<i<<": ";
        for (int j=0;j<=i;++j)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }**/
    for (int i=0;i<=n;++i)
    {
        ans=max(ans,dp[n][i]);
    }
    cout<<ans;
    return 0;
}