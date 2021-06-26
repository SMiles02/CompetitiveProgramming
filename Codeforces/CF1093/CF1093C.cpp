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
    ll n,k;
    cin>>n;
    ll a[n];
    a[0]=0;
    cin>>a[n-1];
    for (int i=1;i<n/2;++i)
    {
        cin>>k;
        a[i]=a[i-1];
        a[n-1-i]=k-a[i];
        if (a[n-1-i]>a[n-i])
        {
            a[n-1-i]=a[n-i];
            a[i]=k-a[n-1-i];
        }
    }
    for (int i=0;i<n;++i)
        cout<<a[i]<<" ";
    return 0;
}