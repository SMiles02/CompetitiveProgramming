#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn=2000,mod=1e9+7;
int dpL[mn][mn],dpR[mn][mn],dpU[mn][mn],dpD[mn][mn],dp[mn][mn];
ll INV[5000000];

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
        return (res * a)%mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h,w,cur=0;
    cin>>h>>w;
    ll ans=0,tot;
    string s[h];
    INV[0]=1;
    INV[1]=(mod+1)/2;
    for (int i=2;i<5000000;++i)
        INV[i]=(INV[i-1]*INV[1])%mod;
    for (int i=0;i<h;++i)
        cin>>s[i];
    for (int i=0;i<h;++i)
        for (int j=0;j<w;++j)
            if (s[i][j]=='.')
            {
                ++cur;
                if (i>0)
                    ++dpU[i-1][j];
                if (j>0)
                    ++dpL[i][j-1];
                if (j+1<w)
                    ++dpR[i][j+1];
                ++dpD[i][j];
            }
    tot=binpow(2,cur);
    for (int i=0;i<h;++i)
        for (int j=0;j<w;++j)
        {
            if (i>0)
                dpD[i][j]+=dpD[i-1][j];
            if (j>0)
                dpR[i][j]+=dpR[i][j-1];
            if (s[i][j]=='#')
            {
                dpD[i][j]=0;
                dpR[i][j]=0;
            }
            dp[i][j]+=dpD[i][j];
            dp[i][j]+=dpR[i][j];
        }
    for (int i=h-1;i>=0;--i)
        for (int j=w-1;j>=0;--j)
        {
            if (i<h-1)
                dpU[i][j]+=dpU[i+1][j];
            if (j<w-1)
                dpL[i][j]+=dpL[i][j+1];
            if (s[i][j]=='#')
            {
                dpU[i][j]=0;
                dpL[i][j]=0;
            }
            dp[i][j]+=dpU[i][j];
            dp[i][j]+=dpL[i][j];
        }
    for (int i=0;i<h;++i)
        for (int j=0;j<w;++j)
            if (s[i][j]=='.')
            {
                ans+=tot;
                if (ans>=mod)
                    ans-=mod;
                ans-=((INV[dp[i][j]]*tot)%mod);
                if (ans<0)
                    ans+=mod;
            }
    cout<<ans;
    return 0;
}