#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
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

int n;
double p[18][18];
double dp[131072][19];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    if (n==1)
    {
        cout<<"1.000000";
        return 0;
    }
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cin>>p[i][j];
    int k=binpow(2,n-1)-1;
    for (int i=1;i<n;++i)
    {
        dp[k][i]=p[0][i];
    }
    for (int i=0;i<k;++i)
        for (int j=1;j<n;++j)
            dp[i][j]=0;
    for (int x=k-1;x+1;--x)
    {
        for (int i=1;i<n;++i)
        {
            if (x&(1<<(i-1)))
            {
                for (int j=1;j<n;++j)
                {
                    if (!(x&(1<<(j-1))))
                    {
                        dp[x][i]=max(dp[x][i],dp[x|(1<<(j-1))][i]*p[i][j]+dp[x|(1<<(j-1))][j]*p[j][i]);
                    }
                    //cout<<"dp["<<x<<"]["<<i<<"] = "<<dp[x][i]<<"\n";
                }
            }
        }
    }
    double ans=0;
    for (int i=1;i<n;++i)
        for (int j=1;j<n;++j)
            ans=max(ans,dp[1<<(i-1)][j]);
    cout<<fixed<<setprecision(7)<<ans;
    return 0;
}