#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
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
    int n,m,k,l,r,mid,ans=0;
    cin>>n>>m>>k;
    ll a[n+1];
    ll b[m+1];
    a[0]=0;
    b[0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    for (int i=1;i<=m;++i)
    {
        cin>>b[i];
        b[i]+=b[i-1];
    }
    for (int i=0;i<=n;++i)
    {
        if (a[i]>k)
            continue;
        l=0;r=m;
        while (l<r)
        {
            mid=l+(r-l)/2+1;
            if (a[i]+b[mid]<=k)
                l=mid;
            else
                r=mid-1;
        }
        ans=max(ans,i+l);
    }
    cout<<ans;
    return 0;
}