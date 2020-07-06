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
    ll t,k,MOD=1000000007,a,b;
    cin>>t>>k;
    ll dp[100001][2];
    dp[0][0]=1;
    dp[0][1]=0;
    for (int i=1;i<k;++i)
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=0;
        dp[i][0]%=MOD;
        //cout<<i<<": "<<dp[i][0]<<", "<<dp[i][1]<<"\n";
    }
    //return 0;
    for (int i=k;i<100001;++i)
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-k][0]+dp[i-k][1];
        dp[i][0]%=MOD;
        dp[i][1]%=MOD;
        //cout<<i<<": "<<dp[i][0]<<", "<<dp[i][1]<<"\n";
    }
    //return 0;
    ll sum[100001];
    sum[0]=0;
    for (int i=1;i<100001;++i)
    {
        sum[i]=sum[i-1]+dp[i][0]+dp[i][1];
        sum[i]%=MOD;
    }
    while (t--)
    {
        cin>>a>>b;
        k=sum[b]-sum[a-1];
        while (k<0)
        {
            k+=MOD;
        }
        cout<<k<<"\n";
    }
    return 0;
}