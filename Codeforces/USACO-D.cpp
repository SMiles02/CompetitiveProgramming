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
    int n,x=0;
    cin>>n;
    ll a[n+1],ans=0;
    a[0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    if (a[n]%3)
    {
        cout<<0;
        return 0;
    }
    for (int i=1;i<n;++i)
    {
        if (!(a[i]&1)&&(a[i]/2)*3==a[n])
            ans+=x;
        if (a[i]*3==a[n])
            ++x;
    }
    cout<<ans;
    return 0;
}