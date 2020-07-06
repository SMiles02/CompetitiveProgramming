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

ll max(ll a, ll b)
{
    if (a>b) return a;
    return b;
}

int goodPairs[19][19];
ll dp[524288][19]; //dp[mask][lastTaken]=maxScore

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,x,y,c;
    cin>>n>>m>>k;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (m==1)
    {
        int maxi=0;
        for (int i=1;i<=n;++i)
            maxi=max(maxi,a[i]);
        cout<<maxi;
        return 0;
    }
    for (int i=0;i<k;++i)
    {
        cin>>x>>y>>c;
        goodPairs[x][y]=c;
    }
    x=binpow(2,n+1);
    ll ans=0;
    for (int i=1;i<x;++i)
    {
        if (__builtin_popcount(i)==1)
        {
            for (int j=1;j<=n;++j)
            {
                if ((1<<(j-1))==i)
                {
                    dp[i][j]=a[j];
                }
            }
            continue;
        }
        for (int j=1;j<=n;++j)
        {
            if (i&(1<<(j-1)))
            {
                for (int l=1;l<=n;++l)
                {
                    if (i&(1<<(l-1))&&j!=l)
                    {
                        if (goodPairs[l][j])
                        {
                            dp[i][j]=max(dp[i][j],dp[i&~(1<<(j-1))][l]+a[j]+goodPairs[l][j]);
                        }
                        else
                            dp[i][j]=max(dp[i][j],dp[i&~(1<<(j-1))][l]+a[j]);
                    }
                }
                if (__builtin_popcount(i)==m)
                {
                    ans=max(ans,dp[i][j]);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}