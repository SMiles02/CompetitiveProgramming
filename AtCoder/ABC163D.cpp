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
    ll ans=0,mini,maxi,mod=1000000007,n,k;
    cin>>n>>k;
    for (ll i=k;i<=n+1;++i)
    {
        mini=i*(i+1);
        mini/=2;
        maxi=((n+1)*(n+2))/2;
        maxi-=((n+1-i)*(n+2-i))/2;
        ans+=maxi-mini+1;
        ans%=mod;
        //cout<<"i: "<<i<<" - maxi: "<<maxi<<" - mini: "<<mini<<"\n";
    }
    cout<<ans;
    return 0;
}