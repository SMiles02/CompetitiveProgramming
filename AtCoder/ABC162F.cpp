#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if (n%2==0)
    {
        ll f=0,s=0,newF,newS;
        for (int i=0;i<n;i+=2)
        {
            newF=f+a[i];
            newS=max(f,s)+a[i+1];
            f=newF;
            s=newS;
        }
        cout<<max(f,s);
        return 0;
    }
    ll dp[n][2][2];
    dp[0][0][0]=0;
    dp[1][0][0]=0;
    dp[0][0][1]=0;
    dp[1][0][1]=0;
    dp[0][1][1]=a[0];
    dp[1][1][1]=a[1];
    dp[0][1][0]=-1000000000000000000;
    dp[1][1][0]=-1000000000000000000;
    for (int i=2;i<n-1;i+=2)
    {
        dp[i][0][0]=max(dp[i-1][1][1],dp[i-1][1][0]);
        dp[i][0][1]=dp[i-1][0][0]+a[i];
        dp[i][1][0]=-1000000000000000000;
        dp[i][1][1]=max(dp[i-1][1][0],dp[i-2][1][1])+a[i];
        dp[i+1][0][0]=max(dp[i][0][0],dp[i][0][1]);
        dp[i+1][0][1]=dp[i-1][0][0];
        dp[i+1][0][1]+=a[i+1];
        dp[i+1][1][0]=dp[i][1][1];
        dp[i+1][1][1]=max(dp[i-1][1][1],dp[i-2][1][1]);
        dp[i+1][1][1]+=a[i+1];
    }
    cout<<max(max(dp[n-3][0][0],dp[n-3][0][1])+a[n-1],max(dp[n-3][1][1],dp[n-2][1][1]));
    return 0;
}