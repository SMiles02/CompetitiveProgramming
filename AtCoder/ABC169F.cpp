#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=998244353;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
    {
        return (res * a)%mod;
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

ll dp[3001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s,k,h=499122177;
    cin>>n;
    cin>>s;
    dp[0]=(binpow(2,n)-1+mod)%mod;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        for (int j=s;j-k>=0;--j)
            if (dp[j-k]>0)
                dp[j]+=(dp[j-k]*h-1+mod)%mod;
        cout<<"i="<<i<<": \n";
        for (int j=0;j<=s;++j)
            cout<<dp[j]<<" ";
        cout<<"\n";
    }
    cout<<dp[s];
    return 0;
}