#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,l,r,mid;
    cin>>n;
    int a[n+1],p[n+1];
    ll pre[n+1];
    pre[0]=0;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    {
        cin>>p[i];
        pre[i]=pre[i-1]+p[i];
    }
    cin>>m;
    int b[m+1];
    ll dp[m+1],lastTaken[m+1],INF=1e18;
    dp[0]=0;
    lastTaken[0]=0;
    for (int i=1;i<=m;++i)
    {
        cin>>b[i];
        dp[i]=INF;
        lastTaken[i]=INF;
    }
    for (int i=1;i<=n;++i)
    {
        l=1;r=m;
        while (l<r)
        {
            mid=l+(r-l)/2;
            //cout<<l<<" "<<r<<" "<<mid<<"!\n";
            if (a[i]<b[mid])
                r=max(l,mid-1);
            else if (a[i]==b[mid])
            {
                l=mid;
                r=mid;
            }
            else
                l=min(r,mid+1);
            //cout<<l<<" "<<r<<"!!\n";
        }
        //cout<<a[i]<<" "<<b[l]<<"\n";
        /**if (i>2) 
        {
            for (int i=0;i<=m;++i)
                cout<<dp[i]<<" "<<lastTaken[i]<<"\n";
            cout<<"\n";
        }**/
        /**if (i==5)
            return 0;**/
        if (a[i]==b[l])
        {
            //cout<<"l="<<l<<": "<<lastTaken[l-1]<<"!!!\n";
            if (lastTaken[l-1]!=INF)
            {
                if (lastTaken[l]==INF)
                {
                    dp[l]=dp[l-1]+pre[i-1]-pre[lastTaken[l-1]];
                    lastTaken[l]=i;
                }
                if (p[i]>p[lastTaken[l]])
                {
                    dp[l]+=pre[i-1]-pre[lastTaken[l]-1];
                    lastTaken[l]=i;
                    //cout<<"testicular cancer\n";
                }
                if (dp[l]>dp[l-1]+pre[i-1]-pre[lastTaken[l-1]])
                {
                    dp[l]=dp[l-1]+pre[i-1]-pre[lastTaken[l-1]];
                    lastTaken[l]=i;
                }
                cout<<"l="<<l<<": "<<dp[l]<<" "<<lastTaken[l]<<"\n";
            }
        }
        //if (i==5) return 0;
    }
    for (int i=0;i<=m;++i)
        cout<<dp[i]<<" ";
    cout<<"\n";
    if (dp[m]==1e18)
        cout<<"NO";
    else
        cout<<"YES\n"<<dp[m]+pre[n]-pre[lastTaken[m]];
    return 0;
}