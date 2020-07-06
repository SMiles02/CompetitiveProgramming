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
    int n,r,ans=0;
    bool b;
    cin>>n>>r;
    int dp[n];
    for (int i=0;i<n;++i)
    {
        cin>>b;
        dp[i]=10000;
        if (b)
        {
            if (i<r)
                dp[i]=1;
            for (int j=i-1;j>max(-1,i-2*r);--j)
                dp[i]=min(dp[i],dp[j]+1);
        }
        //cout<<dp[i]<<"\n";
    }
    ans=10000;
    for (int i=max(0,n-r);i<n;++i)
        ans=min(ans,dp[i]);
    if (ans>n)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}