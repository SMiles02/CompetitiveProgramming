#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
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
    int n;
    ll ans=0,MOD=1000000007,sum=0;
    cin>>n;
    ll a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
        sum%=MOD;
    }
    for (int i=0;i<n-1;++i)
    {
        ans+=(a[i]^(sum-a[i]));
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}